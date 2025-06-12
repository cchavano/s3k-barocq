#pragma once

#define S3K_SLOT_CNT 32
#define S3K_PROC_CNT 8
#define S3K_CAP_CNT 32
#define S3K_PMP_CNT 8
#define S3K_CHAN_CNT 8

// Length of slots in ticks.
#define S3K_SLOT_LEN (S3K_RTC_HZ / S3K_SLOT_CNT)

// RTC frequency
#define S3K_RTC_HZ 1000000ull
