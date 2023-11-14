# Corel apps generc crack

There are several ways to unlock trial version of Corel app. The materials and information here are guides how patch Corel executable to remove trial limitations. All this is for educational purpose.

# dta descrambler
dta files contain informations about serial code. Serial code contains information about license type and trial period. The code is published for educational purpose. Full srial number generator is not available to public yet.

# Method
Simplest method to bypass trial limitations is to patch PASMUTILITY.dll and redirect serial number parser to parse trial as normal. Just replace PASMUTILITY.dll in Your Corel path and have full verison.
Tested on:
CorelDraw Version 24.5.0.731
Corel Painter 23.0.0.244

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


