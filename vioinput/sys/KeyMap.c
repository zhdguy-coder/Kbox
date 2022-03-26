/*
 * EV_KEY EVDEV code to HID usage code map
 *
 * Copyright (c) 2016-2017 Red Hat, Inc.
 *
 * Author(s):
 *  Ladi Prosek <lprosek@redhat.com>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met :
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and / or other materials provided with the distribution.
 * 3. Neither the names of the copyright holders nor the names of their contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "precomp.h"
#include "Hid.h"

static const ULONG ReportCodeToUsageCodeTable[] =
{
    /* KEY_RESERVED */           0x00,
    /* KEY_ESC */                0x29,
    /* KEY_1 */                  0x1E,
    /* KEY_2 */                  0x1F,
    /* KEY_3 */                  0x20,
    /* KEY_4 */                  0x21,
    /* KEY_5 */                  0x22,
    /* KEY_6 */                  0x23,
    /* KEY_7 */                  0x24,
    /* KEY_8 */                  0x25,
    /* KEY_9 */                  0x26,
    /* KEY_0 */                  0x27,
    /* KEY_MINUS */              0x2D,
    /* KEY_EQUAL */              0x2E,
    /* KEY_BACKSPACE */          0x2A,
    /* KEY_TAB */                0x2B,
    /* KEY_Q */                  0x14,
    /* KEY_W */                  0x1A,
    /* KEY_E */                  0x08,
    /* KEY_R */                  0x15,
    /* KEY_T */                  0x17,
    /* KEY_Y */                  0x1C,
    /* KEY_U */                  0x18,
    /* KEY_I */                  0x0C,
    /* KEY_O */                  0x12,
    /* KEY_P */                  0x13,
    /* KEY_LEFTBRACE */          0x2F,
    /* KEY_RIGHTBRACE */         0x30,
    /* KEY_ENTER */              0x28,
    /* KEY_LEFTCTRL */           0xE0,
    /* KEY_A */                  0x04,
    /* KEY_S */                  0x16,
    /* KEY_D */                  0x07,
    /* KEY_F */                  0x09,
    /* KEY_G */                  0x0A,
    /* KEY_H */                  0x0B,
    /* KEY_J */                  0x0D,
    /* KEY_K */                  0x0E,
    /* KEY_L */                  0x0F,
    /* KEY_SEMICOLON */          0x33,
    /* KEY_APOSTROPHE */         0x34,
    /* KEY_GRAVE */              0x35,
    /* KEY_LEFTSHIFT */          0xE1,
    /* KEY_BACKSLASH */          0x32,
    /* KEY_Z */                  0x1D,
    /* KEY_X */                  0x1B,
    /* KEY_C */                  0x06,
    /* KEY_V */                  0x19,
    /* KEY_B */                  0x05,
    /* KEY_N */                  0x11,
    /* KEY_M */                  0x10,
    /* KEY_COMMA */              0x36,
    /* KEY_DOT */                0x37,
    /* KEY_SLASH */              0x38,
    /* KEY_RIGHTSHIFT */         0xE5,
    /* KEY_KPASTERISK */         0x55,
    /* KEY_LEFTALT */            0xE2,
    /* KEY_SPACE */              0x2C,
    /* KEY_CAPSLOCK */           0x39,
    /* KEY_F1 */                 0x3A,
    /* KEY_F2 */                 0x3B,
    /* KEY_F3 */                 0x3C,
    /* KEY_F4 */                 0x3D,
    /* KEY_F5 */                 0x3E,
    /* KEY_F6 */                 0x3F,
    /* KEY_F7 */                 0x40,
    /* KEY_F8 */                 0x41,
    /* KEY_F9 */                 0x42,
    /* KEY_F10 */                0x43,
    /* KEY_NUMLOCK */            0x53,
    /* KEY_SCROLLLOCK */         0x47,
    /* KEY_KP7 */                0x5F,
    /* KEY_KP8 */                0x60,
    /* KEY_KP9 */                0x61,
    /* KEY_KPMINUS */            0x56,
    /* KEY_KP4 */                0x5C,
    /* KEY_KP5 */                0x5D,
    /* KEY_KP6 */                0x5E,
    /* KEY_KPPLUS */             0x57,
    /* KEY_KP1 */                0x59,
    /* KEY_KP2 */                0x5A,
    /* KEY_KP3 */                0x5B,
    /* KEY_KP0 */                0x62,
    /* KEY_KPDOT */              0x63,
    /* unused */                 0x00,
    /* KEY_ZENKAKUHANKAKU */     0x94,
    /* KEY_102ND */              0x64,
    /* KEY_F11 */                0x44,
    /* KEY_F12 */                0x45,
    /* KEY_RO */                 0x87,
    /* KEY_KATAKANA */           0x92,
    /* KEY_HIRAGANA */           0x93,
    /* KEY_HENKAN */             0x8A,
    /* KEY_KATAKANAHIRAGANA */   0x88,
    /* KEY_MUHENKAN */           0x8B,
    /* KEY_KPJPCOMMA */          0x8C,
    /* KEY_KPENTER */            0x58,
    /* KEY_RIGHTCTRL */          0xE4,
    /* KEY_KPSLASH */            0x54,
    /* KEY_SYSRQ */              0x46,
    /* KEY_RIGHTALT */           0xE6,
    /* KEY_LINEFEED */           0x00,
    /* KEY_HOME */               0x4A,
    /* KEY_UP */                 0x52,
    /* KEY_PAGEUP */             0x4B,
    /* KEY_LEFT */               0x50,
    /* KEY_RIGHT */              0x4F,
    /* KEY_END */                0x4D,
    /* KEY_DOWN */               0x51,
    /* KEY_PAGEDOWN */           0x4E,
    /* KEY_INSERT */             0x49,
    /* KEY_DELETE */             0x4C,
    /* KEY_MACRO */              0x00,
    /* KEY_MUTE */               KEY_TYPE_CONSUMER | 0xE2,
    /* KEY_VOLUMEDOWN */         KEY_TYPE_CONSUMER | 0xEA,
    /* KEY_VOLUMEUP */           KEY_TYPE_CONSUMER | 0xE9,
    /* KEY_POWER */              KEY_TYPE_CONSUMER | 0x30,
    /* KEY_KPEQUAL */            0x67,
    /* KEY_KPPLUSMINUS */        0x00,
    /* KEY_PAUSE */              0x48,
    /* KEY_SCALE */              0x00,
    /* KEY_KPCOMMA */            0x85,
    /* KEY_HANGEUL */            0x90,
    /* KEY_HANJA */              0x91,
    /* KEY_YEN */                0x89,
    /* KEY_LEFTMETA */           0xE3,
    /* KEY_RIGHTMETA */          0xE7,
    /* KEY_COMPOSE */            0x65,
    /* KEY_STOP */               KEY_TYPE_CONSUMER | 0x226,
    /* KEY_AGAIN */              0x79,
    /* KEY_PROPS */              0x76,
    /* KEY_UNDO */               0x7A,
    /* KEY_FRONT */              0x77,
    /* KEY_COPY */               0x7C,
    /* KEY_OPEN */               0x74,
    /* KEY_PASTE */              0x7D,
    /* KEY_FIND */               0xF4,
    /* KEY_CUT */                0x7B,
    /* KEY_HELP */               0x75,
    /* KEY_MENU */               0x65,
    /* KEY_CALC */               KEY_TYPE_CONSUMER | 0x192,
    /* KEY_SETUP */              0x00,
    /* KEY_SLEEP */              KEY_TYPE_CONSUMER | 0x32,
    /* KEY_WAKEUP */             0x00,
    /* KEY_FILE */               KEY_TYPE_CONSUMER | 0x194,
    /* KEY_SENDFILE */           0x00,
    /* KEY_DELETEFILE */         0x00,
    /* KEY_XFER */               0x00,
    /* KEY_PROG1 */              0x00,
    /* KEY_PROG2 */              0x00,
    /* KEY_WWW */                KEY_TYPE_CONSUMER | 0x196,
    /* KEY_MSDOS */              0x00,
    /* KEY_COFFEE */             KEY_TYPE_CONSUMER | 0x19E,
    /* KEY_ROTATE_DISPLAY */     0x00,
    /* KEY_CYCLEWINDOWS */       0x00,
    /* KEY_MAIL */               KEY_TYPE_CONSUMER | 0x18A,
    /* KEY_BOOKMARKS */          KEY_TYPE_CONSUMER | 0x182,
    /* KEY_COMPUTER */           0x00,
    /* KEY_BACK */               KEY_TYPE_CONSUMER | 0x224,
    /* KEY_FORWARD */            KEY_TYPE_CONSUMER | 0x225,
    /* KEY_CLOSECD */            0x00,
    /* KEY_EJECTCD */            KEY_TYPE_CONSUMER | 0xB8,
    /* KEY_EJECTCLOSECD */       0x00,
    /* KEY_NEXTSONG */           KEY_TYPE_CONSUMER | 0xB5,
    /* KEY_PLAYPAUSE */          KEY_TYPE_CONSUMER | 0xCD,
    /* KEY_PREVIOUSSONG */       KEY_TYPE_CONSUMER | 0xB6,
    /* KEY_STOPCD */             KEY_TYPE_CONSUMER | 0xB7,
    /* KEY_RECORD */             KEY_TYPE_CONSUMER | 0xB2,
    /* KEY_REWIND */             KEY_TYPE_CONSUMER | 0xB4,
    /* KEY_PHONE */              KEY_TYPE_CONSUMER | 0x8C,
    /* KEY_ISO */                0x00,
    /* KEY_CONFIG */             KEY_TYPE_CONSUMER | 0x183,
    /* KEY_HOMEPAGE */           KEY_TYPE_CONSUMER | 0x223,
    /* KEY_REFRESH */            KEY_TYPE_CONSUMER | 0x227,
    /* KEY_EXIT */               KEY_TYPE_CONSUMER | 0x94,
    /* KEY_MOVE */               0x00,
    /* KEY_EDIT */               KEY_TYPE_CONSUMER | 0x23D,
    /* KEY_SCROLLUP */           KEY_TYPE_CONSUMER | 0x233,
    /* KEY_SCROLLDOWN */         KEY_TYPE_CONSUMER | 0x234,
    /* KEY_KPLEFTPAREN */        0xB6,
    /* KEY_KPRIGHTPAREN */       0xB7,
    /* KEY_NEW */                KEY_TYPE_CONSUMER | 0x201,
    /* KEY_REDO */               KEY_TYPE_CONSUMER | 0x279,
    /* KEY_F13 */                0x68,
    /* KEY_F14 */                0x69,
    /* KEY_F15 */                0x6A,
    /* KEY_F16 */                0x6B,
    /* KEY_F17 */                0x6C,
    /* KEY_F18 */                0x6D,
    /* KEY_F19 */                0x6E,
    /* KEY_F20 */                0x6F,
    /* KEY_F21 */                0x70,
    /* KEY_F22 */                0x71,
    /* KEY_F23 */                0x72,
    /* KEY_F24 */                0x73,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* KEY_PLAYCD */             0x00,
    /* KEY_PAUSECD */            0x00,
    /* KEY_PROG3 */              0x00,
    /* KEY_PROG4 */              0x00,
    /* KEY_DASHBOARD */          0x00,
    /* KEY_SUSPEND */            0x00,
    /* KEY_CLOSE */              KEY_TYPE_CONSUMER | 0x203,
    /* KEY_PLAY */               KEY_TYPE_CONSUMER | 0xB0,
    /* KEY_FASTFORWARD */        KEY_TYPE_CONSUMER | 0xB3,
    /* KEY_BASSBOOST */          KEY_TYPE_CONSUMER | 0xE5,
    /* KEY_PRINT */              KEY_TYPE_CONSUMER | 0x208,
    /* KEY_HP */                 0x00,
    /* KEY_CAMERA */             KEY_TYPE_CONSUMER | 0x65,
    /* KEY_SOUND */              0x00,
    /* KEY_QUESTION */           0x00,
    /* KEY_EMAIL */              0x00,
    /* KEY_CHAT */               KEY_TYPE_CONSUMER | 0x199,
    /* KEY_SEARCH */             KEY_TYPE_CONSUMER | 0x221,
    /* KEY_CONNECT */            0x00,
    /* KEY_FINANCE */            KEY_TYPE_CONSUMER | 0x191,
    /* KEY_SPORT */              0x00,
    /* KEY_SHOP */               0x00,
    /* KEY_ALTERASE */           0x00,
    /* KEY_CANCEL */             KEY_TYPE_CONSUMER | 0x25F,
    /* KEY_BRIGHTNESSDOWN */     KEY_TYPE_CONSUMER | 0x70,
    /* KEY_BRIGHTNESSUP */       KEY_TYPE_CONSUMER | 0x6F,
    /* KEY_MEDIA */              0x00,
    /* KEY_SWITCHVIDEOMODE */    0x00,
    /* KEY_KBDILLUMTOGGLE */     KEY_TYPE_CONSUMER | 0x35,
    /* KEY_KBDILLUMDOWN */       0x00,
    /* KEY_KBDILLUMUP */         0x00,
    /* KEY_SEND */               KEY_TYPE_CONSUMER | 0x28C,
    /* KEY_REPLY */              KEY_TYPE_CONSUMER | 0x289,
    /* KEY_FORWARDMAIL */        KEY_TYPE_CONSUMER | 0x28B,
    /* KEY_SAVE */               KEY_TYPE_CONSUMER | 0x207,
    /* KEY_DOCUMENTS */          KEY_TYPE_CONSUMER | 0x1A7,
    /* KEY_BATTERY */            0x00,
    /* KEY_BLUETOOTH */          0x00,
    /* KEY_WLAN */               0x00,
    /* KEY_UWB */                0x00,
    /* KEY_UNKNOWN */            0x00,
    /* KEY_VIDEO_NEXT */         KEY_TYPE_CONSUMER | 0x82,
    /* KEY_VIDEO_PREV */         0x00,
    /* KEY_BRIGHTNESS_CYCLE */   0x00,
    /* KEY_BRIGHTNESS_AUTO */    KEY_TYPE_CONSUMER | 0x75,
    /* KEY_DISPLAY_OFF */        0x00,
    /* KEY_WWAN */               0x00,
    /* KEY_RFKILL */             0x00,
    /* KEY_MICMUTE */            0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* KEY_OK */                 0x00,
    /* KEY_SELECT */             KEY_TYPE_CONSUMER | 0x41,
    /* KEY_GOTO */               KEY_TYPE_CONSUMER | 0x222,
    /* KEY_CLEAR */              0x00,
    /* KEY_POWER2 */             0x00,
    /* KEY_OPTION */             0x00,
    /* KEY_INFO */               KEY_TYPE_CONSUMER | 0x60,
    /* KEY_TIME */               0x00,
    /* KEY_VENDOR */             0x00,
    /* KEY_ARCHIVE */            0x00,
    /* KEY_PROGRAM */            KEY_TYPE_CONSUMER | 0x8D,
    /* KEY_CHANNEL */            0x00,
    /* KEY_FAVORITES */          0x00,
    /* KEY_EPG */                0x00,
    /* KEY_PVR */                KEY_TYPE_CONSUMER | 0x9A,
    /* KEY_MHP */                0x00,
    /* KEY_LANGUAGE */           0x00,
    /* KEY_TITLE */              0x00,
    /* KEY_SUBTITLE */           KEY_TYPE_CONSUMER | 0x61,
    /* KEY_ANGLE */              0x00,
    /* KEY_ZOOM */               KEY_TYPE_CONSUMER | 0x6D,
    /* KEY_MODE */               0x00,
    /* KEY_KEYBOARD */           KEY_TYPE_CONSUMER | 0x1AE,
    /* KEY_SCREEN */             0x00,
    /* KEY_PC */                 KEY_TYPE_CONSUMER | 0x88,
    /* KEY_TV */                 KEY_TYPE_CONSUMER | 0x89,
    /* KEY_TV2 */                KEY_TYPE_CONSUMER | 0x97,
    /* KEY_VCR */                KEY_TYPE_CONSUMER | 0x92,
    /* KEY_VCR2 */               KEY_TYPE_CONSUMER | 0xA0,
    /* KEY_SAT */                KEY_TYPE_CONSUMER | 0x98,
    /* KEY_SAT2 */               0x00,
    /* KEY_CD */                 KEY_TYPE_CONSUMER | 0x91,
    /* KEY_TAPE */               KEY_TYPE_CONSUMER | 0x96,
    /* KEY_RADIO */              0x00,
    /* KEY_TUNER */              KEY_TYPE_CONSUMER | 0x93,
    /* KEY_PLAYER */             KEY_TYPE_CONSUMER | 0x193,
    /* KEY_TEXT */               0x00,
    /* KEY_DVD */                KEY_TYPE_CONSUMER | 0x8B,
    /* KEY_AUX */                0x00,
    /* KEY_MP3 */                0x00,
    /* KEY_AUDIO */              KEY_TYPE_CONSUMER | 0x1B7,
    /* KEY_VIDEO */              KEY_TYPE_CONSUMER | 0x1B8,
    /* KEY_DIRECTORY */          0x00,
    /* KEY_LIST */               0x00,
    /* KEY_MEMO */               KEY_TYPE_CONSUMER | 0x90,
    /* KEY_CALENDAR */           KEY_TYPE_CONSUMER | 0x18E,
    /* KEY_RED */                KEY_TYPE_CONSUMER | 0x69,
    /* KEY_GREEN */              KEY_TYPE_CONSUMER | 0x6A,
    /* KEY_YELLOW */             KEY_TYPE_CONSUMER | 0x6C,
    /* KEY_BLUE */               KEY_TYPE_CONSUMER | 0x6B,
    /* KEY_CHANNELUP */          KEY_TYPE_CONSUMER | 0x9C,
    /* KEY_CHANNELDOWN */        KEY_TYPE_CONSUMER | 0x9D,
    /* KEY_FIRST */              0x00,
    /* KEY_LAST */               KEY_TYPE_CONSUMER | 0x83,
    /* KEY_AB */                 0x00,
    /* KEY_NEXT */               KEY_TYPE_CONSUMER | 0x1A3,
    /* KEY_RESTART */            KEY_TYPE_CONSUMER | 0x31,
    /* KEY_SLOW */               KEY_TYPE_CONSUMER | 0xF5,
    /* KEY_SHUFFLE */            KEY_TYPE_CONSUMER | 0xB9,
    /* KEY_BREAK */              0x00,
    /* KEY_PREVIOUS */           KEY_TYPE_CONSUMER | 0x1A4,
    /* KEY_DIGITS */             0x00,
    /* KEY_TEEN */               0x00,
    /* KEY_TWEN */               0x00,
    /* KEY_VIDEOPHONE */         KEY_TYPE_CONSUMER | 0x8E,
    /* KEY_GAMES */              KEY_TYPE_CONSUMER | 0x8F,
    /* KEY_ZOOMIN */             KEY_TYPE_CONSUMER | 0x22D,
    /* KEY_ZOOMOUT */            KEY_TYPE_CONSUMER | 0x22E,
    /* KEY_ZOOMRESET */          KEY_TYPE_CONSUMER | 0x22F,
    /* KEY_WORDPROCESSOR */      KEY_TYPE_CONSUMER | 0x184,
    /* KEY_EDITOR */             KEY_TYPE_CONSUMER | 0x185,
    /* KEY_SPREADSHEET */        KEY_TYPE_CONSUMER | 0x186,
    /* KEY_GRAPHICSEDITOR */     KEY_TYPE_CONSUMER | 0x187,
    /* KEY_PRESENTATION */       KEY_TYPE_CONSUMER | 0x188,
    /* KEY_DATABASE */           KEY_TYPE_CONSUMER | 0x189,
    /* KEY_NEWS */               KEY_TYPE_CONSUMER | 0x18B,
    /* KEY_VOICEMAIL */          KEY_TYPE_CONSUMER | 0x18C,
    /* KEY_ADDRESSBOOK */        KEY_TYPE_CONSUMER | 0x18D,
    /* KEY_MESSENGER */          KEY_TYPE_CONSUMER | 0x1BC,
    /* KEY_DISPLAYTOGGLE */      KEY_TYPE_CONSUMER | 0x72,
    /* KEY_SPELLCHECK */         KEY_TYPE_CONSUMER | 0x1AB,
    /* KEY_LOGOFF */             KEY_TYPE_CONSUMER | 0x19C,
    /* KEY_DOLLAR */             0x00,
    /* KEY_EURO */               0x00,
    /* KEY_FRAMEBACK */          0x00,
    /* KEY_FRAMEFORWARD */       0x00,
    /* KEY_CONTEXT_MENU */       0x00,
    /* KEY_MEDIA_REPEAT */       KEY_TYPE_CONSUMER | 0xBC,
    /* KEY_10CHANNELSUP */       0x00,
    /* KEY_10CHANNELSDOWN */     0x00,
    /* KEY_IMAGES */             KEY_TYPE_CONSUMER | 0x1B6,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* KEY_DEL_EOL */            0x00,
    /* KEY_DEL_EOS */            0x00,
    /* KEY_INS_LINE */           0x00,
    /* KEY_DEL_LINE */           0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* KEY_FN */                 0x00,
    /* KEY_FN_ESC */             0x00,
    /* KEY_FN_F1 */              0x00,
    /* KEY_FN_F2 */              0x00,
    /* KEY_FN_F3 */              0x00,
    /* KEY_FN_F4 */              0x00,
    /* KEY_FN_F5 */              0x00,
    /* KEY_FN_F6 */              0x00,
    /* KEY_FN_F7 */              0x00,
    /* KEY_FN_F8 */              0x00,
    /* KEY_FN_F9 */              0x00,
    /* KEY_FN_F10 */             0x00,
    /* KEY_FN_F11 */             0x00,
    /* KEY_FN_F12 */             0x00,
    /* KEY_FN_1 */               0x00,
    /* KEY_FN_2 */               0x00,
    /* KEY_FN_D */               0x00,
    /* KEY_FN_E */               0x00,
    /* KEY_FN_F */               0x00,
    /* KEY_FN_S */               0x00,
    /* KEY_FN_B */               0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* KEY_BRL_DOT1 */           0x00,
    /* KEY_BRL_DOT2 */           0x00,
    /* KEY_BRL_DOT3 */           0x00,
    /* KEY_BRL_DOT4 */           0x00,
    /* KEY_BRL_DOT5 */           0x00,
    /* KEY_BRL_DOT6 */           0x00,
    /* KEY_BRL_DOT7 */           0x00,
    /* KEY_BRL_DOT8 */           0x00,
    /* KEY_BRL_DOT9 */           0x00,
    /* KEY_BRL_DOT10 */          0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* KEY_NUMERIC_0 */          0x00,
    /* KEY_NUMERIC_1 */          0x00,
    /* KEY_NUMERIC_2 */          0x00,
    /* KEY_NUMERIC_3 */          0x00,
    /* KEY_NUMERIC_4 */          0x00,
    /* KEY_NUMERIC_5 */          0x00,
    /* KEY_NUMERIC_6 */          0x00,
    /* KEY_NUMERIC_7 */          0x00,
    /* KEY_NUMERIC_8 */          0x00,
    /* KEY_NUMERIC_9 */          0x00,
    /* KEY_NUMERIC_STAR */       0x00,
    /* KEY_NUMERIC_POUND */      0x00,
    /* KEY_NUMERIC_A */          0x00,
    /* KEY_NUMERIC_B */          0x00,
    /* KEY_NUMERIC_C */          0x00,
    /* KEY_NUMERIC_D */          0x00,
    /* KEY_CAMERA_FOCUS */       0x00,
    /* KEY_WPS_BUTTON */         0x00,
    /* KEY_TOUCHPAD_TOGGLE */    0x00,
    /* KEY_TOUCHPAD_ON */        0x00,
    /* KEY_TOUCHPAD_OFF */       0x00,
    /* KEY_CAMERA_ZOOMIN */      0x00,
    /* KEY_CAMERA_ZOOMOUT */     0x00,
    /* KEY_CAMERA_UP */          0x00,
    /* KEY_CAMERA_DOWN */        0x00,
    /* KEY_CAMERA_LEFT */        0x00,
    /* KEY_CAMERA_RIGHT */       0x00,
    /* KEY_ATTENDANT_ON */       0x00,
    /* KEY_ATTENDANT_OFF */      0x00,
    /* KEY_ATTENDANT_TOGGLE */   0x00,
    /* KEY_LIGHTS_TOGGLE */      0x00,
    /* unused */                 0x00,
    /* BTN_DPAD_UP */            0x00,
    /* BTN_DPAD_DOWN */          0x00,
    /* BTN_DPAD_LEFT */          0x00,
    /* BTN_DPAD_RIGHT */         0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* KEY_ALS_TOGGLE */         0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* KEY_BUTTONCONFIG */       KEY_TYPE_CONSUMER | 0x181,
    /* KEY_TASKMANAGER */        KEY_TYPE_CONSUMER | 0x18F,
    /* KEY_JOURNAL */            KEY_TYPE_CONSUMER | 0x190,
    /* KEY_CONTROLPANEL */       KEY_TYPE_CONSUMER | 0x19F,
    /* KEY_APPSELECT */          KEY_TYPE_CONSUMER | 0x1A2,
    /* KEY_SCREENSAVER */        KEY_TYPE_CONSUMER | 0x1B1,
    /* KEY_VOICECOMMAND */       KEY_TYPE_CONSUMER | 0xCF,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* KEY_BRIGHTNESS_MIN */     KEY_TYPE_CONSUMER | 0x73,
    /* KEY_BRIGHTNESS_MAX */     KEY_TYPE_CONSUMER | 0x74,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* unused */                 0x00,
    /* KEY_KBDINPUTASSIST_PREV */       KEY_TYPE_CONSUMER | 0x2C7,
    /* KEY_KBDINPUTASSIST_NEXT */       KEY_TYPE_CONSUMER | 0x2C8,
    /* KEY_KBDINPUTASSIST_PREVGROUP */  KEY_TYPE_CONSUMER | 0x2C9,
    /* KEY_KBDINPUTASSIST_NEXTGROUP */  KEY_TYPE_CONSUMER | 0x2CA,
    /* KEY_KBDINPUTASSIST_ACCEPT */     KEY_TYPE_CONSUMER | 0x2CB,
    /* KEY_KBDINPUTASSIST_CANCEL */     KEY_TYPE_CONSUMER | 0x2CC,
};

ULONG
HIDKeyboardEventCodeToUsageCode(
    USHORT uEventCode)
{
    if (uEventCode < (sizeof(ReportCodeToUsageCodeTable) / sizeof(ReportCodeToUsageCodeTable[0])))
    {
        return ReportCodeToUsageCodeTable[uEventCode];
    }
    return 0;
}