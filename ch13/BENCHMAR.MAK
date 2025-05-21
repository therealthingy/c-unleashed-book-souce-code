# Microsoft Developer Studio Generated NMAKE File, Based on Benchmar.dsp
!IF "$(CFG)" == ""
CFG=benchmark - Win32 Debug
!MESSAGE No configuration specified. Defaulting to benchmark - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "benchmark - Win32 Release" && "$(CFG)" != "benchmark - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Benchmar.mak" CFG="benchmark - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "benchmark - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "benchmark - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "benchmark - Win32 Release"

OUTDIR=.\benchmark___Win32_Release
INTDIR=.\benchmark___Win32_Release
# Begin Custom Macros
OutDir=.\benchmark___Win32_Release
# End Custom Macros

ALL : "$(OUTDIR)\Benchmar.exe"


CLEAN :
	-@erase "$(INTDIR)\cockus.obj"
	-@erase "$(INTDIR)\distribs.obj"
	-@erase "$(INTDIR)\double.obj"
	-@erase "$(INTDIR)\keyxfrm.obj"
	-@erase "$(INTDIR)\sint.obj"
	-@erase "$(INTDIR)\STRINGS.OBJ"
	-@erase "$(INTDIR)\test.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Benchmar.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /G6 /Gr /ML /W3 /GX /O2 /Ob2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\Benchmar.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Benchmar.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\Benchmar.pdb" /machine:I386 /out:"$(OUTDIR)\Benchmar.exe" 
LINK32_OBJS= \
	"$(INTDIR)\cockus.obj" \
	"$(INTDIR)\distribs.obj" \
	"$(INTDIR)\double.obj" \
	"$(INTDIR)\keyxfrm.obj" \
	"$(INTDIR)\sint.obj" \
	"$(INTDIR)\STRINGS.OBJ" \
	"$(INTDIR)\test.obj"

"$(OUTDIR)\Benchmar.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "benchmark - Win32 Debug"

OUTDIR=.\benchmark___Win32_Debug
INTDIR=.\benchmark___Win32_Debug
# Begin Custom Macros
OutDir=.\benchmark___Win32_Debug
# End Custom Macros

ALL : "$(OUTDIR)\Benchmar.exe"


CLEAN :
	-@erase "$(INTDIR)\cockus.obj"
	-@erase "$(INTDIR)\distribs.obj"
	-@erase "$(INTDIR)\double.obj"
	-@erase "$(INTDIR)\keyxfrm.obj"
	-@erase "$(INTDIR)\sint.obj"
	-@erase "$(INTDIR)\STRINGS.OBJ"
	-@erase "$(INTDIR)\test.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Benchmar.exe"
	-@erase "$(OUTDIR)\Benchmar.ilk"
	-@erase "$(OUTDIR)\Benchmar.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\Benchmar.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Benchmar.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\Benchmar.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Benchmar.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\cockus.obj" \
	"$(INTDIR)\distribs.obj" \
	"$(INTDIR)\double.obj" \
	"$(INTDIR)\keyxfrm.obj" \
	"$(INTDIR)\sint.obj" \
	"$(INTDIR)\STRINGS.OBJ" \
	"$(INTDIR)\test.obj"

"$(OUTDIR)\Benchmar.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Benchmar.dep")
!INCLUDE "Benchmar.dep"
!ELSE 
!MESSAGE Warning: cannot find "Benchmar.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "benchmark - Win32 Release" || "$(CFG)" == "benchmark - Win32 Debug"
SOURCE=.\cockus.c

"$(INTDIR)\cockus.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\distribs.c

"$(INTDIR)\distribs.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\double.c

"$(INTDIR)\double.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\keyxfrm.c

"$(INTDIR)\keyxfrm.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\sint.c

"$(INTDIR)\sint.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\STRINGS.C

"$(INTDIR)\STRINGS.OBJ" : $(SOURCE) "$(INTDIR)"


SOURCE=.\test.c

"$(INTDIR)\test.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

