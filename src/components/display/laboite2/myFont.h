const MD_MAX72XX::fontType_t myFont[] PROGMEM = {
    0, // char 0
    0, // char 1
    0, // char 2
    0, // char 3
    0, // char 4
    0, // char 5
    0, // char 6
    0, // char 7
    0, // char 8
    0, // char 9
    0, // char 10
    0, // char 11
    0, // char 12
    0, // char 13
    0, // char 14
    0, // char 15
    0, // char 16
    0, // char 17
    0, // char 18
    0, // char 19
    0, // char 20
    0, // char 21
    0, // char 22
    0, // char 23
    0, // char 24
    0, // char 25
    0, // char 26
    0, // char 27
    0, // char 28
    0, // char 29
    0, // char 30
    0, // char 31
    2, 0x0, 0x0, // char 32 - " "
    1, 0xb8, // char 33 - "!"
    3, 0x18, 0x0, 0x18, // char 34 - """
    4, 0x50, 0xf8, 0xf8, 0x50, // char 35 - "#"
    3, 0x5c, 0xfe, 0x74, // char 36 - "$"
    3, 0x48, 0x20, 0x90, // char 37 - "%"
    1, 0x0, // char 38 - "&"
    1, 0x8, // char 39 - "'"
    2, 0x70, 0x88, // char 40 - "("
    2, 0x88, 0x70, // char 41 - ")"
    1, 0x0, // char 42 - "*"
    3, 0x40, 0xe0, 0x40, // char 43 - "+"
    1, 0x80, // char 44 - ","
    2, 0x40, 0x40, // char 45 - "-"
    1, 0x80, // char 46 - "."
    3, 0x80, 0x40, 0x20, // char 47 - "/"
    3, 0xf8, 0x88, 0xf8, // char 48 - "0"
    1, 0xf8, // char 49 - "1"
    3, 0xe8, 0xa8, 0xb8, // char 50 - "2"
    3, 0x88, 0xa8, 0xf8, // char 51 - "3"
    3, 0x38, 0x20, 0xf0, // char 52 - "4"
    3, 0xb8, 0xa8, 0xe8, // char 53 - "5"
    3, 0xf8, 0xa8, 0xe8, // char 54 - "6"
    3, 0x8, 0xe8, 0x18, // char 55 - "7"
    3, 0xf8, 0xa8, 0xf8, // char 56 - "8"
    3, 0xb8, 0xa8, 0xf8, // char 57 - "9"
    1, 0xa0, // char 58 - ":"
    1, 0xa0, // char 59 - ";"
    0, // char 60
    0, // char 61
    0, // char 62
    0, // char 63
    0, // char 64
    0, // char 65
    0, // char 66
    0, // char 67
    0, // char 68
    0, // char 69
    0, // char 70
    0, // char 71
    0, // char 72
    0, // char 73
    0, // char 74
    0, // char 75
    0, // char 76
    0, // char 77
    0, // char 78
    0, // char 79
    0, // char 80
    0, // char 81
    0, // char 82
    0, // char 83
    0, // char 84
    0, // char 85
    0, // char 86
    0, // char 87
    0, // char 88
    0, // char 89
    0, // char 90
    0, // char 91
    0, // char 92
    0, // char 93
    0, // char 94
    0, // char 95
    0, // char 96
    0, // char 97
    0, // char 98
    0, // char 99
    0, // char 100
    0, // char 101
    0, // char 102
    0, // char 103
    0, // char 104
    0, // char 105
    0, // char 106
    0, // char 107
    0, // char 108
    0, // char 109
    0, // char 110
    0, // char 111
    0, // char 112
    0, // char 113
    0, // char 114
    0, // char 115
    0, // char 116
    0, // char 117
    0, // char 118
    0, // char 119
    0, // char 120
    0, // char 121
    0, // char 122
    0, // char 123
    0, // char 124
    0, // char 125
    0, // char 126
    0, // char 127
    0, // char 128
    0, // char 129
    0, // char 130
    0, // char 131
    0, // char 132
    0, // char 133
    0, // char 134
    0, // char 135
    0, // char 136
    0, // char 137
    0, // char 138
    0, // char 139
    0, // char 140
    0, // char 141
    0, // char 142
    0, // char 143
    0, // char 144
    0, // char 145
    0, // char 146
    0, // char 147
    0, // char 148
    0, // char 149
    0, // char 150
    0, // char 151
    0, // char 152
    0, // char 153
    0, // char 154
    0, // char 155
    0, // char 156
    0, // char 157
    0, // char 158
    0, // char 159
    0, // char 160
    0, // char 161
    0, // char 162
    0, // char 163
    0, // char 164
    0, // char 165
    0, // char 166
    0, // char 167
    0, // char 168
    0, // char 169
    0, // char 170
    0, // char 171
    0, // char 172
    0, // char 173
    0, // char 174
    0, // char 175
    0, // char 176
    0, // char 177
    0, // char 178
    0, // char 179
    0, // char 180
    0, // char 181
    0, // char 182
    0, // char 183
    0, // char 184
    0, // char 185
    0, // char 186
    0, // char 187
    0, // char 188
    0, // char 189
    0, // char 190
    0, // char 191
    0, // char 192
    0, // char 193
    0, // char 194
    0, // char 195
    0, // char 196
    0, // char 197
    0, // char 198
    0, // char 199
    0, // char 200
    0, // char 201
    0, // char 202
    0, // char 203
    0, // char 204
    0, // char 205
    0, // char 206
    0, // char 207
    0, // char 208
    0, // char 209
    0, // char 210
    0, // char 211
    0, // char 212
    0, // char 213
    0, // char 214
    0, // char 215
    0, // char 216
    0, // char 217
    0, // char 218
    0, // char 219
    0, // char 220
    0, // char 221
    0, // char 222
    0, // char 223
    0, // char 224
    0, // char 225
    0, // char 226
    0, // char 227
    0, // char 228
    0, // char 229
    0, // char 230
    0, // char 231
    0, // char 232
    0, // char 233
    0, // char 234
    0, // char 235
    0, // char 236
    0, // char 237
    0, // char 238
    0, // char 239
    0, // char 240
    0, // char 241
    0, // char 242
    0, // char 243
    0, // char 244
    0, // char 245
    0, // char 246
    0, // char 247
    0, // char 248
    0, // char 249
    0, // char 250
    0, // char 251
    0, // char 252
    0, // char 253
    0, // char 254
    0, // char 255
};
