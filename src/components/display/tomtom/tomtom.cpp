#include "tomtom.h"

TomtomDisplayImpl::TomtomDisplayImpl() {
    display = new PxMATRIX(32, 16, P_LAT, P_OE, P_A, P_B, P_C);
}

void TomtomDisplayImpl::setup(DebugInterface *debug) {
    display->begin(8);
    display->setFastUpdate(true);
    clearDisplay();
    display->setCursor(2, 0);
    display->setFont(&Picopixel);
    display->setTextColor(display->color565(125, 125, 125));
    display->print("192.168.15.3");
    display_ticker = new Ticker();
    display_ticker->attach_ms(2, &TomtomDisplayImpl::display_updater, this);
}

void TomtomDisplayImpl::loop() {
    drawFrame(mario_frame_1);
    drawFrame(mario_frame_2);
    drawFrame(mario_frame_3);
    drawFrame(mario_frame_4);
    drawFrame(mario_frame_5);
    drawFrame(mario_frame_6);
    drawFrame(mario_frame_7);
    drawFrame(mario_frame_8);
    drawFrame(mario_frame_9);
    drawFrame(mario_frame_10);
    drawFrame(mario_frame_11);
    drawFrame(mario_frame_12);
}

// ISR for display refresh
void TomtomDisplayImpl::display_updater(TomtomDisplayImpl *tomtomDisplay) {
    tomtomDisplay->display->display(tomtomDisplay->display_draw_time);
}

void TomtomDisplayImpl::clearDisplay() {
    display->clearDisplay();
}

void TomtomDisplayImpl::drawFrame(uint16_t *frame) {
    //clearDisplay();
    int imageHeight = 16;
    int imageWidth = 32;
    int counter = 0;
    for (int yy = 0; yy < imageHeight; yy++) {
        for (int xx = 0; xx < imageWidth; xx++) {
            display->drawPixel(xx, yy, frame[counter]);
            counter++;
        }
    }
    delay(100);
}

void TomtomDisplayImpl::displayHour(int hour, int minutes) {
}

void TomtomDisplayImpl::setCoordStatus(int i, int j, bool state) {
}

void TomtomDisplayImpl::displayWifiStatus(bool wifiStatus) {
}

void TomtomDisplayImpl::displayTemp(int temp) {
}

void TomtomDisplayImpl::displayConfigurationMode(bool confEnabled) {
}

void TomtomDisplayImpl::displayOtaProgress(int progressPercent) {
}

void TomtomDisplayImpl::displayIpAddress(String ipAddress) {
}
