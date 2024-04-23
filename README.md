# Corel apps generc crack
There are several ways to unlock trial version of Corel app. The materials and information here are guides how patch Corel executable to remove trial limitations. All this is for educational purpose.

# dta descrambler
dta files contain informations about serial code. Serial code contains information about license type and trial period. The code is published for educational purpose. Full srial number generator is not available to public yet.

# Method
Simplest method to bypass trial limitations is to patch PASMUTILITY.dll and redirect serial number parser to parse trial as normal. Just replace PASMUTILITY.dll in Your Corel path and have full verison.
Tested on:
* CorelDraw Version 24.5.0.731
* Corel Painter 23.0.0.244
* CorelDraw Version 25.0.0.230

# Patched places

Function responsible for serial number mapping:
```
C:\Program Files\Corel\PASMUtility\v1\PASMUTILITY.dll

__int64 __fastcall letter_to_number_1800AFD10(char a1)
{
  unsigned int v2;

  switch ( a1 )
  {
    case 'B':
      v2 = 5;
      break;
    case 'C':
      v2 = 0;
      break;
    case 'D':
      v2 = 9;
      break;
    case 'E':
      v2 = 2;
      break;
    case 'N':
      v2 = 4;
      break;
    case 'R':
      v2 = 1;
      break;
    case 'S':
      v2 = 15; <---- 15 days, set to 0
      break;
    case 'T':
      v2 = 8; <---- trial license, set to 1
      break;
    case 'U':
      v2 = 3; <--- change to 1
      break;
    case 'X':
      v2 = 10;
      break;
    default:
      v2 = 16;
      break;
  }
  return v2;
}
```

IDA look of above function:
```
.text:00000001800AFD10                         ; __int64 __fastcall letter_to_number_1800AFD10(char)
.text:00000001800AFD10                         letter_to_number_1800AFD10 proc near    ; CODE XREF: sub_1800AF980+6A↑p
.text:00000001800AFD10                                                                 ; sub_1800B38C0+24E↓p
.text:00000001800AFD10                                                                 ; DATA XREF: ...
.text:00000001800AFD10
.text:00000001800AFD10                         var_18          = dword ptr -18h
.text:00000001800AFD10                         var_14          = dword ptr -14h
.text:00000001800AFD10                         arg_0           = byte ptr  8
.text:00000001800AFD10
.text:00000001800AFD10 88 4C 24 08                             mov     [rsp+arg_0], cl
.text:00000001800AFD14 48 83 EC 18                             sub     rsp, 18h
.text:00000001800AFD18 C7 04 24 10 00 00 00                    mov     [rsp+18h+var_18], 10h
.text:00000001800AFD1F 0F BE 44 24 20                          movsx   eax, [rsp+18h+arg_0]
.text:00000001800AFD24 89 44 24 04                             mov     [rsp+18h+var_14], eax
.text:00000001800AFD28 8B 44 24 04                             mov     eax, [rsp+18h+var_14]
.text:00000001800AFD2C 83 E8 42                                sub     eax, 42h ; 'B'  ; switch 23 cases
.text:00000001800AFD2F 89 44 24 04                             mov     [rsp+18h+var_14], eax
.text:00000001800AFD33 83 7C 24 04 16                          cmp     [rsp+18h+var_14], 16h
.text:00000001800AFD38 77 72                                   ja      short def_1800AFD50 ; jumptable 00000001800AFD50 default case, cases 70-77,79-81,86,87
.text:00000001800AFD3A 48 63 44 24 04                          movsxd  rax, [rsp+18h+var_14]
.text:00000001800AFD3F 48 8D 0D BA 02 F5 FF                    lea     rcx, __ImageBase
.text:00000001800AFD46 8B 84 81 BC FD 0A 00                    mov     eax, ds:(jpt_1800AFD50 - 180000000h)[rcx+rax*4]
.text:00000001800AFD4D 48 03 C1                                add     rax, rcx
.text:00000001800AFD50 FF E0                                   jmp     rax             ; switch jump
.text:00000001800AFD52                         ; ---------------------------------------------------------------------------
.text:00000001800AFD52
.text:00000001800AFD52                         loc_1800AFD52:                          ; CODE XREF: letter_to_number_1800AFD10+40↑j
.text:00000001800AFD52                                                                 ; DATA XREF: letter_to_number_1800AFD10:jpt_1800AFD50↓o
.text:00000001800AFD52 C7 04 24 05 00 00 00                    mov     [rsp+18h+var_18], 5 ; jumptable 00000001800AFD50 case 66
.text:00000001800AFD59 EB 58                                   jmp     short loc_1800AFDB3
.text:00000001800AFD5B                         ; ---------------------------------------------------------------------------
.text:00000001800AFD5B
.text:00000001800AFD5B                         loc_1800AFD5B:                          ; CODE XREF: letter_to_number_1800AFD10+40↑j
.text:00000001800AFD5B                                                                 ; DATA XREF: letter_to_number_1800AFD10:jpt_1800AFD50↓o
.text:00000001800AFD5B C7 04 24 00 00 00 00                    mov     [rsp+18h+var_18], 0 ; jumptable 00000001800AFD50 case 67
.text:00000001800AFD62 EB 4F                                   jmp     short loc_1800AFDB3
.text:00000001800AFD64                         ; ---------------------------------------------------------------------------
.text:00000001800AFD64
.text:00000001800AFD64                         loc_1800AFD64:                          ; CODE XREF: letter_to_number_1800AFD10+40↑j
.text:00000001800AFD64                                                                 ; DATA XREF: letter_to_number_1800AFD10:jpt_1800AFD50↓o
.text:00000001800AFD64 C7 04 24 09 00 00 00                    mov     [rsp+18h+var_18], 9 ; jumptable 00000001800AFD50 case 68
.text:00000001800AFD6B EB 46                                   jmp     short loc_1800AFDB3
.text:00000001800AFD6D                         ; ---------------------------------------------------------------------------
.text:00000001800AFD6D
.text:00000001800AFD6D                         loc_1800AFD6D:                          ; CODE XREF: letter_to_number_1800AFD10+40↑j
.text:00000001800AFD6D                                                                 ; DATA XREF: letter_to_number_1800AFD10:jpt_1800AFD50↓o
.text:00000001800AFD6D C7 04 24 02 00 00 00                    mov     [rsp+18h+var_18], 2 ; jumptable 00000001800AFD50 case 69
.text:00000001800AFD74 EB 3D                                   jmp     short loc_1800AFDB3
.text:00000001800AFD76                         ; ---------------------------------------------------------------------------
.text:00000001800AFD76
.text:00000001800AFD76                         loc_1800AFD76:                          ; CODE XREF: letter_to_number_1800AFD10+40↑j
.text:00000001800AFD76                                                                 ; DATA XREF: letter_to_number_1800AFD10:jpt_1800AFD50↓o
.text:00000001800AFD76 C7 04 24 04 00 00 00                    mov     [rsp+18h+var_18], 4 ; jumptable 00000001800AFD50 case 78
.text:00000001800AFD7D EB 34                                   jmp     short loc_1800AFDB3
.text:00000001800AFD7F                         ; ---------------------------------------------------------------------------
.text:00000001800AFD7F
.text:00000001800AFD7F                         loc_1800AFD7F:                          ; CODE XREF: letter_to_number_1800AFD10+40↑j
.text:00000001800AFD7F                                                                 ; DATA XREF: letter_to_number_1800AFD10:jpt_1800AFD50↓o
.text:00000001800AFD7F C7 04 24 01 00 00 00                    mov     [rsp+18h+var_18], 1 ; jumptable 00000001800AFD50 case 82
.text:00000001800AFD86 EB 2B                                   jmp     short loc_1800AFDB3
.text:00000001800AFD88                         ; ---------------------------------------------------------------------------
.text:00000001800AFD88
.text:00000001800AFD88                         loc_1800AFD88:                          ; CODE XREF: letter_to_number_1800AFD10+40↑j
.text:00000001800AFD88                                                                 ; DATA XREF: letter_to_number_1800AFD10:jpt_1800AFD50↓o
.text:00000001800AFD88 C7 04 24 01 00 00 00                    mov     [rsp+18h+var_18], 1
.text:00000001800AFD8F EB 22                                   jmp     short loc_1800AFDB3
.text:00000001800AFD91                         ; ---------------------------------------------------------------------------
.text:00000001800AFD91
.text:00000001800AFD91                         loc_1800AFD91:                          ; CODE XREF: letter_to_number_1800AFD10+40↑j
.text:00000001800AFD91                                                                 ; DATA XREF: letter_to_number_1800AFD10:jpt_1800AFD50↓o
.text:00000001800AFD91 C7 04 24 01 00 00 00                    mov     [rsp+18h+var_18], 1
.text:00000001800AFD98 EB 19                                   jmp     short loc_1800AFDB3
.text:00000001800AFD9A                         ; ---------------------------------------------------------------------------
.text:00000001800AFD9A
.text:00000001800AFD9A                         loc_1800AFD9A:                          ; CODE XREF: letter_to_number_1800AFD10+40↑j
.text:00000001800AFD9A                                                                 ; DATA XREF: letter_to_number_1800AFD10:jpt_1800AFD50↓o
.text:00000001800AFD9A C7 04 24 0A 00 00 00                    mov     [rsp+18h+var_18], 0Ah ; jumptable 00000001800AFD50 case 88
.text:00000001800AFDA1 EB 10                                   jmp     short loc_1800AFDB3
.text:00000001800AFDA3                         ; ---------------------------------------------------------------------------
.text:00000001800AFDA3
.text:00000001800AFDA3                         loc_1800AFDA3:                          ; CODE XREF: letter_to_number_1800AFD10+40↑j
.text:00000001800AFDA3                                                                 ; DATA XREF: letter_to_number_1800AFD10:jpt_1800AFD50↓o
.text:00000001800AFDA3 C7 04 24 00 00 00 00                    mov     [rsp+18h+var_18], 0
.text:00000001800AFDAA EB 07                                   jmp     short loc_1800AFDB3
.text:00000001800AFDAC                         ; ---------------------------------------------------------------------------
.text:00000001800AFDAC
.text:00000001800AFDAC                         def_1800AFD50:                          ; CODE XREF: letter_to_number_1800AFD10+28↑j
.text:00000001800AFDAC                                                                 ; letter_to_number_1800AFD10+40↑j
.text:00000001800AFDAC                                                                 ; DATA XREF: ...
.text:00000001800AFDAC C7 04 24 10 00 00 00                    mov     [rsp+18h+var_18], 10h ; jumptable 00000001800AFD50 default case, cases 70-77,79-81,86,87
.text:00000001800AFDB3
.text:00000001800AFDB3                         loc_1800AFDB3:                          ; CODE XREF: letter_to_number_1800AFD10+49↑j
.text:00000001800AFDB3                                                                 ; letter_to_number_1800AFD10+52↑j ...
.text:00000001800AFDB3 8B 04 24                                mov     eax, [rsp+18h+var_18]
.text:00000001800AFDB6 48 83 C4 18                             add     rsp, 18h
.text:00000001800AFDBA C3                                      retn
.text:00000001800
```


```
this is function that takes process number of tiral deys, compares to 15, this is max period
put to 0 to comapre to
text:0000000180053BD0                         sub_180053BD0   proc near               ; DATA XREF: .rdata:0000000180373700↓o
.text:0000000180053BD0                                                                 ; .pdata:00000001804F56B8↓o
.text:0000000180053BD0
.text:0000000180053BD0                         var_18          = dword ptr -18h
.text:0000000180053BD0                         arg_0           = qword ptr  8
.text:0000000180053BD0                         arg_8           = qword ptr  10h
.text:0000000180053BD0
.text:0000000180053BD0 48 89 54 24 10                          mov     [rsp+arg_8], rdx
.text:0000000180053BD5 48 89 4C 24 08                          mov     [rsp+arg_0], rcx
.text:0000000180053BDA 48 83 EC 38                             sub     rsp, 38h
.text:0000000180053BDE C7 44 24 20 00 00 00 00                 mov     [rsp+38h+var_18], 0
.text:0000000180053BE6 48 8B 44 24 40                          mov     rax, [rsp+38h+arg_0]
.text:0000000180053BEB 48 05 C0 01 00 00                       add     rax, 1C0h
.text:0000000180053BF1 48 8B C8                                mov     rcx, rax
.text:0000000180053BF4 E8 87 74 06 00                          call    sub_1800BB080
.text:0000000180053BF9 83 F8 0F                                cmp     eax, 0x0F                    <------ 83 F8 00 cmp     eax, 0x00
.text:0000000180053BFC 75 2B                                   jnz     short loc_180053C29
.text:0000000180053BFE 48 8B 44 24 40                          mov     rax, [rsp+38h+arg_0]
.text:0000000180053C03 48 83 B8 18 15 00 00 00                 cmp     qword ptr [rax+1518h], 0
.text:0000000180053C0B 75 1C                                   jnz     short loc_180053C29
.text:0000000180053C0D 48 8B 54 24 48                          mov     rdx, [rsp+38h+arg_8]
.text:0000000180053C12 48 8B 44 24 40                          mov     rax, [rsp+38h+arg_0]
.text:0000000180053C17 48 8B 88 80 15 00 00                    mov     rcx, [rax+1580h]
.text:0000000180053C1E E8 2D 1B FE FF                          call    sub_180035750
.text:0000000180053C23 89 44 24 20                             mov     [rsp+38h+var_18], eax
.text:0000000180053C27 EB 40                                   jmp     short loc_180053C69
.text:0000000180053C29                         ; ---------------------------------------------------------------------------
.text:0000000180053C29
.text:0000000180053C29                         loc_180053C29:                          ; CODE XREF: sub_180053BD0+2C↑j
.text:0000000180053C29                                                                 ; sub_180053BD0+3B↑j
.text:0000000180053C29 48 8B 44 24 40                          mov     rax, [rsp+38h+arg_0]
.text:0000000180053C2E 48 05 C0 01 00 00                       add     rax, 1C0h
.text:0000000180053C34 48 8B C8                                mov     rcx, rax
.text:0000000180053C37 E8 44 74 06 00                          call    sub_1800BB080
.text:0000000180053C3C 83 F8 0F                                cmp     eax, 0x0F                    <------ 83 F8 00 cmp     eax, 0x00
.text:0000000180053C3F 75 19                                   jnz     short loc_180053C5A
.text:0000000180053C41 48 8B 44 24 40                          mov     rax, [rsp+38h+arg_0]
.text:0000000180053C46 48 05 C8 06 00 00                       add     rax, 6C8h
.text:0000000180053C4C 48 8B C8                                mov     rcx, rax
.text:0000000180053C4F E8 3C 2A 06 00                          call    sub_1800B6690
.text:0000000180053C54 89 44 24 20                             mov     [rsp+38h+var_18], eax
.text:0000000180053C58 EB 0F                                   jmp     short loc_180053C69
.text:0000000180053C5A                         ; ---------------------------------------------------------------------------
.text:0000000180053C5A
.text:0000000180053C5A                         loc_180053C5A:                          ; CODE XREF: sub_180053BD0+6F↑j
.text:0000000180053C5A 48 8B 44 24 40                          mov     rax, [rsp+38h+arg_0]
.text:0000000180053C5F 8B 80 CC 00 00 00                       mov     eax, [rax+0CCh]
.text:0000000180053C65 89 44 24 20                             mov     [rsp+38h+var_18], eax
.text:0000000180053C69
.text:0000000180053C69                         loc_180053C69:                          ; CODE XREF: sub_180053BD0+57↑j
.text:0000000180053C69                                                                 ; sub_180053BD0+88↑j
.text:0000000180053C69 8B 44 24 20                             mov     eax, [rsp+38h+var_18]
.text:0000000180053C6D 48 83 C4 38                             add     rsp, 38h
.text:0000000180053C71 C3                                      retn
.text:0000000180053C71                         sub_180053BD0   endp
```