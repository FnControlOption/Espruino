/*
 * This file is part of Espruino, a JavaScript interpreter for Microcontrollers
 *
 * Copyright (C) 2021 Gordon Williams <gw@pur3.co.uk>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * ----------------------------------------------------------------------------
 * heart rate monitoring
 * ----------------------------------------------------------------------------
 */

#define HRM_SAMPLERATE 50 // Hz
#define HRM_HIST_LEN 16
#define HRM_MEDIAN_LEN 8

#define HRM_THRESH_MIN 3
#define HRM_THRESH_SHIFT 4

typedef struct {
  int8_t raw;
  int8_t filtered;
  int8_t thresh;
  bool wasLow;
  uint8_t timeSinceBeat;
  uint8_t times[HRM_HIST_LEN];
  uint8_t timeIdx; // index in times
  uint16_t bpm10; // 10x BPM
  uint8_t confidence; // 0..100%
} HrmInfo;

extern HrmInfo hrmInfo;

uint16_t hrm_time_to_bpm10(uint8_t time);

/// Initialise heart rate monitoring
void hrm_init();

/// Add new heart rate value, return true if there was a heart beat
bool hrm_new(int hrmValue);
