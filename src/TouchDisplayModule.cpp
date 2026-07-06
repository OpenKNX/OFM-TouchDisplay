#include <Arduino.h>
#include "TouchDisplayModule.h"
#include "lvgl.h"
//#include "lv_xiao_round_screen.h"
#include "knxprod.h"
#include "TouchDisplayScreenFactory.h"
#include "./Pages/Page.h"
#include "./Pages/ProgButtonPage.h"
#include "./ImageLoader.h"
#include "DisplayLed.h"

extern bool touchIsPressed();
extern void displayInit(uint8_t screenRotation);
extern void touchInit();
extern void backgroundLight(bool on);

bool touchIsPressedForLgvl()
{
    return openknxTouchDisplayModule.touchPressStateForLgvl;
}


extern uint8_t screen_rotation;

const std::string TouchDisplayModule::name()
{
    return "TouchRound";
}

const std::string TouchDisplayModule::version()
{
    return MAIN_Version;
}

void TouchDisplayModule::setup()
{
    _displayTimeoutMs = ParamTCH_SwitchOffDelayTimeMS;
    _pageTimeout = ParamTCH_DefaultPageDelayTimeMS;
    _defaultPage = ParamTCH_DefaultPage;
    if (ParamTCH_DefaultPageKO)
    {
        if (KoTCH_DefaultPage.initialized())
            _defaultPage = 1 + (uint8_t) KoTCH_DefaultPage.value(DPT_SceneNumber);
        else
            KoTCH_DefaultPage.requestObjectRead();
    }
    if (ParamTCH_DayNightObject > 0 && !KoTCH_DayNight.initialized())
        KoTCH_DayNight.requestObjectRead();

    if (!KoTCH_PageEnabledA.initialized())
        KoTCH_PageEnabledA.requestObjectRead();
    if (!KoTCH_PageEnabledB.initialized())
        KoTCH_PageEnabledB.requestObjectRead();
    if (!KoTCH_PageEnabledC.initialized())
        KoTCH_PageEnabledC.requestObjectRead();
    if (!KoTCH_PageEnabledD.initialized())
        KoTCH_PageEnabledD.requestObjectRead();
    if (!KoTCH_PageEnabledE.initialized())
        KoTCH_PageEnabledE.requestObjectRead();
    if (!KoTCH_PageEnabledF.initialized())
        KoTCH_PageEnabledF.requestObjectRead();
    if (!KoTCH_PageEnabledG.initialized())
        KoTCH_PageEnabledG.requestObjectRead();
    if (!KoTCH_PageEnabledH.initialized())
        KoTCH_PageEnabledH.requestObjectRead();

    logDebugP("Default Page: %d", _defaultPage);
    showDefaultPage();
    Module::setup();
}

void TouchDisplayModule::processInputKo(GroupObject &ko)
{
    switch (ko.asap())
    {
    case TCH_KoPage:
    {
        uint8_t page = 1 + (uint8_t) ko.value(DPT_SceneNumber);
        logDebugP("Requested Page: %d", page);
        _setPageDelayed = page;
        _setPageDelayedActiveFromSetPageKo = true;
        _setPageDelayedSwitchDisplayOn = ParamTCH_KoPageSwitchOn;
        _waitForSetPageDelayed = max(1UL, millis());
        break;
    }
    case TCH_KoPrevNext:
    {
        if (ko.value(DPT_UpDown))
            nextPage();
        else
            previousPage();
        break;
    }
    case TCH_KoDefaultPage:
    {
        bool isDefaultPageActive = _defaultPage == activePage();
        _defaultPage = 1 + (uint8_t) ko.value(DPT_SceneNumber);
        if (_setPageDelayedActiveFromSetPageKo)
        {
            // set page has higher priority than default page
            break;
        }
        if (isDefaultPageActive)
        {
            _setPageDelayed = _defaultPage;  
            logDebugP("Set Default Page: %d", (int) _defaultPage);
        }
        else
        {
            _setPageDelayed = 255;
            logDebugP("Store Default Page: %d", (int) _defaultPage);
        }
        _setPageDelayedSwitchDisplayOn = ParamTCH_KoDefaultPageSwitchOn;
        _waitForSetPageDelayed = max(1UL, millis());;
        break;
    }
    case TCH_KoDisplayOnOff:
    {
        display(ko.value(DPT_Switch));
        break;
    }
    case TCH_KoDayNight:
    {
        updateTheme();
        break;
    }
    case TCH_KoPageEnabledA:
    case TCH_KoPageEnabledB:
    case TCH_KoPageEnabledC:
    case TCH_KoPageEnabledD:
    case TCH_KoPageEnabledE:
    case TCH_KoPageEnabledF:
    case TCH_KoPageEnabledG:    
    case TCH_KoPageEnabledH:
    {
        
        if (_channelIndex != 255)
        {
            uint8_t page = _channelIndex + 1;
            if (!pageEnabled(page))
            {
                _channelIndex = 255;
                showDefaultPage();
            }   
        }
        else
        {
            showDefaultPage();
        }
        break;
    }
    }
}

void TouchDisplayModule::showDefaultPage()
{
    if (pageEnabled(_defaultPage))
        activatePage(_defaultPage);
    else
        nextPage();
    if (_channelIndex == 255)
    {
        showErrorPage("Keine Seite freigegeben");
    } 
}

uint8_t TouchDisplayModule::activePage()
{
    return _channelIndex + 1;
}       

void TouchDisplayModule::activatePage(uint8_t page, bool displayOnAndResetTimeout)
{
    bool enabled = pageEnabled(page);
    if (!enabled)
    {
        logDebugP("Page: %d not enabled", page);
        return;
    }
    _waitForSetPageDelayed = 0; 
   
   
    auto current = _channelIndex;
    _channelIndex = page - 1;
    if (current == _channelIndex && Page::currentPage() != nullptr && !_detailDevicePageActive)
    {
        logDebugP("Page: %d already activ", page);
        if (displayOnAndResetTimeout)
            display(true);
        return;
    }
    logDebugP("Active Page: %d", page);
    _detailDevicePageActive = false;
    logDebugP("Set KO: %d", _channelIndex);
    KoTCH_CurrentPage.value(_channelIndex, DPT_SceneNumber);
    logDebugP("Create Page: %d", page);
    Page::showPage(Page::createPage(_channelIndex));
    if (displayOnAndResetTimeout)
       _turnOnDisplayInLoop = true;;
}

void TouchDisplayModule::showDetailDevicePage(uint8_t channelIndex, uint8_t deviceIndex)
{
    logDebugP("Show Detail Device %d", deviceIndex + 1);
    _detailDevicePageActive = true;
    Page::showPage(Page::createDetailDevicePage(channelIndex, deviceIndex));
}

void TouchDisplayModule::showProgButtonPage()
{
    display(true);
    _lastTimeoutReset = 0;
    Page::showPage(Page::createProgButtonPage());
}

void TouchDisplayModule::showErrorPage(const char *message)
{
    display(true);
    _lastTimeoutReset = 0;
    Page::showPage(Page::createErrorPage(message, _channelIndex));
}

void TouchDisplayModule::nextPage()
{
    if (knx.configured() && ParamTCH_VisibleChannels > 0)
    {
        _detailDevicePageActive = false;
        uint8_t currentChannel = _channelIndex;
        uint8_t newPage = _channelIndex + 1;
        while (currentChannel != ++_channelIndex)
        {
            if (_channelIndex >= ParamTCH_VisibleChannels)
                _channelIndex = 0;

            uint8_t page = _channelIndex + 1;
            if (ParamTCH_CHNavigation && pageEnabled(page))
            {
                newPage = page;
                break;
            }
        }
        _channelIndex = currentChannel; // restore current channel
        activatePage(newPage);
    }
}


void TouchDisplayModule::previousPage()
{
    if (knx.configured() && ParamTCH_VisibleChannels > 0)
    {
        if (_detailDevicePageActive)
        {
            activatePage(_channelIndex + 1);
            return;
        }
        uint8_t currentChannel = _channelIndex;
        uint8_t newPage = _channelIndex + 1;
        while (currentChannel != --_channelIndex)
        {
            if (_channelIndex >= ParamTCH_VisibleChannels)
                _channelIndex = ParamTCH_VisibleChannels - 1;
            uint8_t page = _channelIndex + 1;
            if (ParamTCH_CHNavigation && pageEnabled(page))
            {
                newPage = page;
                break;
            }
        }
        _channelIndex = currentChannel;
        activatePage(newPage);
    }
}

bool TouchDisplayModule::pageEnabled(uint8_t page)
{
    uint8_t _channelIndex = page - 1;
    if (ParamTCH_CHPageType == 0)
        return false;
  
    
    // <Enumeration Text="Deaktiviert" Value="0" Id="%ENID%" />
    // <Enumeration Text="Seitenfreigabe A" Value="1" Id="%ENID%" />
    // <Enumeration Text="Seitenfreigabe B" Value="2" Id="%ENID%" />
    // <Enumeration Text="Seitenfreigabe C" Value="3" Id="%ENID%" /> 
    // <Enumeration Text="Seitenfreigabe D" Value="4" Id="%ENID%" />
    // <Enumeration Text="Seitenfreigabe E" Value="5" Id="%ENID%" />
    // <Enumeration Text="Seitenfreigabe F" Value="6" Id="%ENID%" />
    // <Enumeration Text="Seitenfreigabe G" Value="7" Id="%ENID%" />
    // <Enumeration Text="Seitenfreigabe H" Value="8" Id="%ENID%" />
    switch (ParamTCH_CHPageEnabled)
    {
    case 1:
        if (ParamTCH_CHPageEnabledValue == (bool) KoTCH_PageEnabledA.value(DPT_Switch))
            return false;
        break;
    case 2:
        if (ParamTCH_CHPageEnabledValue == (bool) KoTCH_PageEnabledB.value(DPT_Switch))
            return false;
        break;
    case 3:
        if (ParamTCH_CHPageEnabledValue == (bool) KoTCH_PageEnabledC.value(DPT_Switch))
            return false;
        break;
    case 4:
        if (ParamTCH_CHPageEnabledValue == (bool) KoTCH_PageEnabledD.value(DPT_Switch))
            return false;
        break;
    case 5:
        if (ParamTCH_CHPageEnabledValue == (bool) KoTCH_PageEnabledE.value(DPT_Switch))
            return false;
        break;
    case 6:
        if (ParamTCH_CHPageEnabledValue == (bool) KoTCH_PageEnabledF.value(DPT_Switch))
            return false;
        break;
    case 7:
        if (ParamTCH_CHPageEnabledValue == (bool) KoTCH_PageEnabledG.value(DPT_Switch))
            return false;
        break;
    case 8: 
        if (ParamTCH_CHPageEnabledValue == (bool) KoTCH_PageEnabledH.value(DPT_Switch))
            return false;
        break;
    }
    
    return true;
}


void TouchDisplayModule::setup(bool configured)
{
    if (configured)
        resetDisplayTimeout();

    lv_init();
#if LV_USE_LOG
    lv_log_register_print_cb(lv_log);
#endif
#if LVGL_VERSION_MAJOR >= 9
#if defined(LV_USE_PNG) && LV_USE_PNG && defined(LV_PNG_H)
    lv_png_init();
#endif
#if LV_USE_LODEPNG
    lv_lodepng_init();
#endif
    lv_tick_set_cb(millis);
#endif
 
    ImageLoader::connectLittleFSwithLVGL();
  
    displayInit(configured ? ParamTCH_DisplayRotation : 0);
    touchInit();
   
    updateTheme();
    touchDisplayScreenFactory().createScreens();

    if (!configured || ParamTCH_SensorKeys)
    {
#ifdef TOUCH_LEFT_PIN
        pinMode(TOUCH_LEFT_PIN, INPUT);
        attachInterrupt(digitalPinToInterrupt(TOUCH_LEFT_PIN), TouchDisplayModule::interruptTouchLeft, CHANGE);
#endif
#ifdef TOUCH_RIGHT_PIN
        pinMode(TOUCH_RIGHT_PIN, INPUT);
        attachInterrupt(digitalPinToInterrupt(TOUCH_RIGHT_PIN), TouchDisplayModule::interruptTouchRight, CHANGE);
#endif
    }

    if (configured)
    {
        if (ParamTCH_Slide)
        {
            if (IScreenNavigation::instance != nullptr)
                IScreenNavigation::instance->init(this);
        }
    }
    _displayOffRectangle = lv_obj_create(lv_layer_top());
    lv_obj_set_size(_displayOffRectangle, LV_HOR_RES, LV_VER_RES);
    lv_obj_set_style_bg_color(_displayOffRectangle, lv_color_black(), 0);
    lv_obj_set_style_border_width(_displayOffRectangle, 0, 0);
    lv_obj_add_flag(_displayOffRectangle, LV_OBJ_FLAG_HIDDEN);
    if (!configured)
    {
        showProgButtonPage();
    }
    Module::setup(configured);
    _setupDone = true;
}

void TouchDisplayModule::updateTheme()
{
    if (!knx.configured())
        setTheme(0, true);
    else
    {
        // <Enumeration Text="Deaktiviert" Value="0" Id="%ENID%" />
        // <Enumeration Text="Umschaltobjekt Nacht EIN" Value="1" Id="%ENID%" />
        // <Enumeration Text="Umschaltobjekt Tag EIN" Value="2" Id="%ENID%" />
        if (ParamTCH_DayNightObject > 0 && KoTCH_DayNight.initialized())
        {
            if (KoTCH_DayNight.value(DPT_Switch))
            {
                if (ParamTCH_DayNightObject == 1)
                    setTheme(ParamTCH_ThemeNight, false);
                else
                    setTheme(ParamTCH_ThemeDay, true);
            }
            else
            {
                if (ParamTCH_DayNightObject == 1)
                    setTheme(ParamTCH_ThemeDay, true);
                else
                    setTheme(ParamTCH_ThemeNight, false);
            }
        }
        else
        {
            setTheme(ParamTCH_ThemeDay, true);
        }
    }
}



void TouchDisplayModule::setTheme(uint8_t themeSelection, bool day)
{
    lv_disp_t *display = lv_disp_get_default();
    // <Enumeration Text="Weiß" Value="3" Id="%ENID%" />
    // <Enumeration Text="Hell" Value="0" Id="%ENID%" />
    // <Enumeration Text="Dunkel" Value="1" Id="%ENID%" />
    // <Enumeration Text="Schwarz" Value="2" Id="%ENID%" />
    _themeSelection = themeSelection;
    bool dark = false;
    switch (themeSelection)
    {
    case 0:
        dark = false;
        touchDisplayScreenFactory().removeBackgroundColor();
        break;
    case 1:
        dark = true;
        touchDisplayScreenFactory().removeBackgroundColor();
        break;
    case 2:
        dark = true;
        touchDisplayScreenFactory().setBackgroundColor(0,0,0);
        break;
    case 3:
        dark = false;
        touchDisplayScreenFactory().setBackgroundColor(255, 255, 255);
        break;
    }
    lv_palette_t main = day ? getPaletteFromConfig(ParamTCH_ColorPaletteDay) : getPaletteFromConfig(ParamTCH_ColorPaletteNight);
    lv_palette_t secondary = day ? getPaletteFromConfig(ParamTCH_ColorPaletteDayOn) : getPaletteFromConfig(ParamTCH_ColorPaletteNightOn);
    logDebugP("Main: %d, Secondary: %d, Dark: %d", (int) main, (int) secondary, (int) dark);
    lv_theme_default_init(display, 
        lv_palette_main(main),
        lv_palette_main(secondary), 
        dark, LV_FONT_DEFAULT);


    lv_obj_t *label = lv_label_create(lv_scr_act());
    _colorInactive = lv_obj_get_style_text_color(label, LV_PART_MAIN);
    lv_obj_del(label);
  
    lv_obj_t *btn = lv_btn_create(lv_scr_act());
#if LVGL_VERSION_MAJOR < 9
 //   lv_obj_add_state(btn, LV_STATE_CHECKED);
    _colorActive = lv_color_make(255,255,0); //  lv_obj_get_style_bg_color(btn, LV_PART_MAIN);
#else
    _colorActive = lv_obj_get_style_bg_color(btn, static_cast<lv_style_selector_t>(LV_PART_MAIN) | static_cast<lv_style_selector_t>(LV_STATE_CHECKED));
#endif
    lv_obj_del(btn); 

        
    if (_setupDone)
        Page::showPage(Page::createPage(_channelIndex));
}

lv_color_t TouchDisplayModule::getActiveColor()
{
    return _colorActive;
}

lv_color_t TouchDisplayModule::getInactiveColor()
{
    return _colorInactive;
}

lv_palette_t TouchDisplayModule::getPaletteFromConfig(uint8_t config)
{
// <Enumeration Text="Rot" Value="1" Id="%ENID%" />
// <Enumeration Text="Pink" Value="2" Id="%ENID%" />
// <Enumeration Text="Lila" Value="3" Id="%ENID%" />
// <Enumeration Text="Dunkel Lila" Value="4" Id="%ENID%" />
// <Enumeration Text="Indigo" Value="5" Id="%ENID%" />
// <Enumeration Text="Blau" Value="6" Id="%ENID%" />
// <Enumeration Text="Hellblau" Value="7" Id="%ENID%" />
// <Enumeration Text="Cyan" Value="8" Id="%ENID%" />
// <Enumeration Text="Türkis" Value="9" Id="%ENID%" />
// <Enumeration Text="Grün" Value="10" Id="%ENID%" />
// <Enumeration Text="Hellgrün" Value="11" Id="%ENID%" />
// <Enumeration Text="Limette" Value="12" Id="%ENID%" />
// <Enumeration Text="Gelb" Value="13" Id="%ENID%" />
// <Enumeration Text="Orange Gelb" Value="14" Id="%ENID%" />
// <Enumeration Text="Orange" Value="15" Id="%ENID%" />
// <Enumeration Text="Dunkel Orange" Value="16" Id="%ENID%" />
// <Enumeration Text="Braun" Value="17" Id="%ENID%" />
// <Enumeration Text="Blau-Grau" Value="18" Id="%ENID%" />
// <Enumeration Text="Grau" Value="19" Id="%ENID%" /> 
switch (config)
{
    case 1:
        return LV_PALETTE_RED;
    case 2:
        return LV_PALETTE_PINK;
    case 3:
        return LV_PALETTE_PURPLE;
    case 4:
        return LV_PALETTE_DEEP_PURPLE;
    case 5:
        return LV_PALETTE_INDIGO;
    case 6:
        return LV_PALETTE_BLUE;
    case 7:
        return LV_PALETTE_LIGHT_BLUE;
    case 8:
        return LV_PALETTE_CYAN;
    case 9:
        return LV_PALETTE_TEAL;
    case 10:
        return LV_PALETTE_GREEN;
    case 11:
        return LV_PALETTE_LIGHT_GREEN;
    case 12:
        return LV_PALETTE_LIME;
    case 13:
        return LV_PALETTE_YELLOW;
    case 14:
        return LV_PALETTE_AMBER;
    case 15:
        return LV_PALETTE_ORANGE;
    case 16:
        return LV_PALETTE_DEEP_ORANGE;
    case 17:
        return LV_PALETTE_BROWN;
    case 18:
        return LV_PALETTE_BLUE_GREY;
    case 19:
        return LV_PALETTE_GREY;
    default:
        return LV_PALETTE_GREY;
    }
}

void TouchDisplayModule::lv_log(
#if LVGL_VERSION_MAJOR >= 9
    lv_log_level_t level, 
#endif
    const char *buf)
{
    logInfo("lvgl", "%s", buf);
}

void TouchDisplayModule::showInformations()
{
}

void TouchDisplayModule::resetDisplayTimeout()
{
    if (_pageTimeout > 0 || _displayTimeoutMs > 0)
    {
        _lastTimeoutReset = max(1UL, millis());
    }
}

bool TouchDisplayModule::isDisplayOn()
{
    return _displayOn;
}

void TouchDisplayModule::display(bool on)
{
    _turnOnDisplayInLoop = false;
    if (on)
        resetDisplayTimeout();
    if (_displayOn == on)
    {
        return;
    }
    _displayOn = false;
    if (on)
    {
        logDebug("Display", "Turn display on.");
        _displayOn = true;
        Page::handleLoop(knx.configured()); // Update page
        backgroundLight(true);
        if (_displayOffRectangle != nullptr)
            lv_obj_add_flag(_displayOffRectangle, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        logDebug("Display", "Turn display off.");
        _displayOn = false;
        if (_displayOffRectangle != nullptr)
            lv_obj_clear_flag(_displayOffRectangle, LV_OBJ_FLAG_HIDDEN);
        backgroundLight(false);
    }
    if (knx.configured())
        KoTCH_DisplayOnOffState.value(_displayOn, DPT_State);
}

void TouchDisplayModule::interruptTouchLeft()
{
#if defined(TOUCH_LEFT_PIN)
    _touchLeftPressed = digitalRead(TOUCH_LEFT_PIN) == HIGH;
#endif
}

void TouchDisplayModule::interruptTouchRight()
{
#if defined(TOUCH_RIGHT_PIN)
    _touchRightPressed = digitalRead(TOUCH_RIGHT_PIN) == HIGH;
#endif
}


void TouchDisplayModule::loop(bool configured)
{
    DisplayLed::handleLeds();
    if (_waitForSetPageDelayed > 0 && millis() - _waitForSetPageDelayed > 100)
    {
        _waitForSetPageDelayed = 0;      
        _setPageDelayedActiveFromSetPageKo = false;
        if (_setPageDelayed == 255)
        {
            // only check for display on
            if (_setPageDelayedSwitchDisplayOn)
                display(true);
        }
        else if (_channelIndex != _setPageDelayed - 1)
        {
            logDebugP("Activate delayed page: %d", _setPageDelayed);
            activatePage(_setPageDelayed, _setPageDelayedSwitchDisplayOn);
        }
        else
        {
            logDebugP("Delayed page %d already active", _setPageDelayed);
            if (_setPageDelayedSwitchDisplayOn)
                display(true);
        }
       
    }
    
    if (configured)
    {
        bool progMode = knx.progMode();
        if (progMode != _progMode)
        {
            _progMode = progMode;
            if (_progMode)
                showProgButtonPage();
            else
                showDefaultPage();
        }
    }

    bool touchPressed = touchIsPressed();
   
    if (touchPressed != _touchPressState)
    {
        _touchPressState = touchPressed;
        logDebugP("Touch %d", touchPressed);
        if (touchPressed)
        {   
            if (!_displayOn)
                display(true);
            else
            {
                _pageAtPressStart = Page::currentPage();
                touchPressStateForLgvl = true;
                _touchPressedTimer = max(1UL, millis());
            }
        }
        else
        {
            touchPressStateForLgvl = false; 
            if (_touchPressedTimer != 0)
            {
                auto page = Page::currentPage();   
                if (page != nullptr)
                {
                    if (page == _pageAtPressStart)
                    {
                        page->shortPressed();
                    }
                    auto currentPage = Page::currentPage();
                    if (currentPage == page)
                        page->resetPressed();
                }             
                _pageAtPressStart = nullptr;
                _touchPressedTimer = 0;
            }
        }
        resetDisplayTimeout();
    }
    if (_touchPressedTimer != 0)
    {
        unsigned long pressedTime = millis() - _touchPressedTimer;
        if (pressedTime > longPressTimeMs)
        {
            _touchPressedTimer = 0;
            auto page = Page::currentPage();  
            if (page != nullptr)
            {
                if (page == _pageAtPressStart)
                {
                    page->longPressed();
                }
                auto currentPage = Page::currentPage();
                if (currentPage == page)
                {
                    page->resetPressed();
                }
            }
            _pageAtPressStart = nullptr;
        }
    }

    lv_timer_handler(); // let the GUI do its work

    Page::handleLoop(configured);
    if (_turnOnDisplayInLoop)
    {
        _turnOnDisplayInLoop = false;
        display(true);
    }
  
    if (_lastTimeoutReset != 0)
    {
        unsigned long now = millis();
        unsigned long pastMs = now - _lastTimeoutReset;

        if (_displayTimeoutMs && _displayOn && pastMs > _displayTimeoutMs)
        {
            logDebugP("Display timeout %d", _displayTimeoutMs);
            display(false);
        }
        if (_pageTimeout && _defaultPage != activePage() && pastMs > _pageTimeout)
        {
            logDebugP("Default page timeout %d", _pageTimeout);
            activatePage(_defaultPage, false);
        }
        if ((_pageTimeout && pastMs > _pageTimeout) && (_displayTimeoutMs && pastMs > _displayTimeoutMs))
        {
            _lastTimeoutReset = 0;
        }
    }

    if (_touchLeftPressed)
    {
        _touchLeftPressed = false;
        if (configured)
        {
            if (_displayOn)
            {
                if (ParamTCH_LeftRightChanged)
                { 
                    nextPage(); 
                }
                else 
                { 
                    previousPage();
                }
            }
            else
                display(true);
        }
        else
        {
            knx.progMode(true);
        }
      
    }

    if (_touchRightPressed)
    {
        _touchRightPressed = false;
        if (configured)
        {
            if (_displayOn)
            {
                if (ParamTCH_LeftRightChanged)
                { 
                    previousPage(); 
                }
                else 
                { 
                    nextPage();
                }
            }
            else
                display(true);
        }
        else
        {
            knx.progMode(false);
        }
    }
}
#ifdef OPENKNX_DUALCORE
void TouchDisplayModule::loop1(bool configured)
{
}
#endif

bool TouchDisplayModule::processCommand(const std::string cmd, bool diagnoseKo)
{
    if (cmd == "lvgl")
    {
        openknx.logger.logWithPrefixAndValues(logPrefix(), "lvgl version: %d.%d.%d", LVGL_VERSION_MAJOR, LVGL_VERSION_MINOR, LVGL_VERSION_PATCH);
        lv_mem_monitor_t mon;
        lv_mem_monitor(&mon);
        printf("Free lvgl memory: %d bytes, Largest free block: %d bytes\n", mon.free_size, mon.free_biggest_size);
        openknx.logger.logWithPrefixAndValues(logPrefix(), "Free: %d bytes, Largest free block: %d bytes",  mon.free_size, mon.free_biggest_size);
        return true;
    }
    if (cmd == "pn")
    {
        openknxTouchDisplayModule.nextPage();
        return true;
    }
    if (cmd == "pp")
    {
        openknxTouchDisplayModule.previousPage();
        return true;
    }
    if (cmd.rfind("p", 0) == 0 && cmd.length() > 1 && cmd[1] >= '0' && cmd[1] <= '9')
    {
        int page = atoi(cmd.substr(1).c_str());
        if (page > 0 && page <= ParamTCH_VisibleChannels)
            openknxTouchDisplayModule.activatePage(page);
        else
            logErrorP("Page %d not available", page);
        return true;
    }
    if (cmd == "d1")
    {
        openknxTouchDisplayModule.display(true);
        return true;
    }
    if (cmd == "d0")
    {
        openknxTouchDisplayModule.display(false);
        return true;
    }
    if (cmd == "t0")
    {
        openknxTouchDisplayModule.setTheme(0, true);
        return true;
    }
    if (cmd == "t1")
    {
        openknxTouchDisplayModule.setTheme(1, true);
        return true;
    }
    if (cmd == "t2")
    {
        openknxTouchDisplayModule.setTheme(2, true);
        return true;
    }
    return false;
}

void TouchDisplayModule::showHelp()
{
    if (!knx.configured())
        return;
    openknx.console.printHelpLine("lvgl", "Show lvgl information");
    openknx.console.printHelpLine("pn", "Next page");
    openknx.console.printHelpLine("pp", "Previous page");
    openknx.console.printHelpLine("p<nn>", "Show page <nn>");
    openknx.console.printHelpLine("d1", "Turn display on");
    openknx.console.printHelpLine("d0", "Turn display off");
    openknx.console.printHelpLine("t0", "Set theme to light");
    openknx.console.printHelpLine("t1", "Set theme to dark");
}

// void TouchDisplayModule::writeFlash()
// {
//     for (size_t i = 0; i < flashSize(); i++)
//     {
//         //openknx.flash.writeByte(0xd0 + i);
//     }
// }

// void TouchDisplayModule::readFlash(const uint8_t* data, const uint16_t size)
// {
//     // printHEX("RESTORE:", data,  len);
// }

// uint16_t TouchDisplayModule::flashSize()
// {
//     return 10;
// }

TouchDisplayModule openknxTouchDisplayModule;