/*
 * SHDLC-Generator: 0.8.2
 * Yaml Version: 0.4.0
 * Template Version: 0.7.0-20-gf035cde
 */
/*
 * Copyright (c) 2021, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <Arduino.h>
#include <SensirionUartSvm41.h>

// Adjust as needed for you Arduino board
#define SENSOR_SERIAL_INTERFACE \
    Serial  // TODO: DRIVER_GENERATOR adjust to Serial1

SensirionUartSvm41 svm41;

// TODO: DRIVER_GENERATOR Add missing commands and make prints more pretty

void setup() {
    uint16_t error;
    char errorMessage[256];

    Serial.begin(115200);
    while (!Serial) {
        delay(100);
    }

    SENSOR_SERIAL_INTERFACE.begin(115200);
    while (!SENSOR_SERIAL_INTERFACE) {
        delay(100);
    }

    svm41.begin(SENSOR_SERIAL_INTERFACE);

    unsigned char serialNumber[255];
    uint8_t serialNumberSize = 255;

    error = svm41.getSerialNumber(serialNumber, serialNumberSize);

    if (error) {
        Serial.print("Error trying to execute getSerialNumber(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("SerialNumber:");
        Serial.println((char*)serialNumber);
    }

    unsigned char productType[255];
    uint8_t productTypeSize = 255;

    error = svm41.getProductType(productType, productTypeSize);

    if (error) {
        Serial.print("Error trying to execute getProductType(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("ProductType:");
        Serial.println((char*)productType);
    }

    unsigned char productName[255];
    uint8_t productNameSize = 255;

    error = svm41.getProductName(productName, productNameSize);

    if (error) {
        Serial.print("Error trying to execute getProductName(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("ProductName:");
        Serial.println((char*)productName);
    }

    uint8_t firmwareMajor;
    uint8_t firmwareMinor;
    bool firmwareDebug;
    uint8_t hardwareMajor;
    uint8_t hardwareMinor;
    uint8_t protocolMajor;
    uint8_t protocolMinor;

    error = svm41.getVersion(firmwareMajor, firmwareMinor, firmwareDebug,
                             hardwareMajor, hardwareMinor, protocolMajor,
                             protocolMinor);

    if (error) {
        Serial.print("Error trying to execute getVersion(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("FirmwareMajor:");
        Serial.print(firmwareMajor);
        Serial.print("\t");
        Serial.print("FirmwareMinor:");
        Serial.print(firmwareMinor);
        Serial.print("\t");
        Serial.print("FirmwareDebug:");
        Serial.print(firmwareDebug);
        Serial.print("\t");
        Serial.print("HardwareMajor:");
        Serial.print(hardwareMajor);
        Serial.print("\t");
        Serial.print("HardwareMinor:");
        Serial.print(hardwareMinor);
        Serial.print("\t");
        Serial.print("ProtocolMajor:");
        Serial.print(protocolMajor);
        Serial.print("\t");
        Serial.print("ProtocolMinor:");
        Serial.println(protocolMinor);
    }

    // Start Measurement

    error = svm41.startMeasurement();

    if (error) {
        Serial.print("Error trying to execute startMeasurement(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    }
}

void loop() {
    uint16_t error;
    char errorMessage[256];

    // TODO: DRIVER_GENERATOR Adjust to correct measurement delay
    delay(1000);
    // Read Measurement
    // TODO: DRIVER_GENERATOR Add scaling and offset to printed measurement
    // values
}
