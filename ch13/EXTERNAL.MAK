# Microsoft Developer Studio Generated NMAKE File, Based on External.dsp
!IF "$(CFG)" == ""
CFG=External - Win32 Debug
!MESSAGE No configuration specified. Defaulting to External - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "External - Win32 Release" && "$(CFG)" != "External - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "External.mak" CFG="External - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "External - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "External - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "External - Win32 Release"

OUTDIR=.\External___Win32_Release
INTDIR=.\External___Win32_Release
# Begin Custom Macros
OutDir=.\External___Win32_Release
# End Custom Macros

ALL : "$(OUTDIR)\External.exe"


CLEAN :
	-@erase "$(INTDIR)\bar.obj"
	-@erase "$(INTDIR)\cockus.obj"
	-@erase "$(INTDIR)\distribs.obj"
	-@erase "$(INTDIR)\double.obj"
	-@erase "$(INTDIR)\keyxfrm.obj"
	-@erase "$(INTDIR)\sint.obj"
	-@erase "$(INTDIR)\STRINGS.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\External.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /ML /W3 /GX /O2 /Ob2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\External.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

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
BSC32_FLAGS=/nologo /o"$(OUTDIR)\External.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:no /pdb:"$(OUTDIR)\External.pdb" /machine:I386 /out:"$(OUTDIR)\External.exe" 
LINK32_OBJS= \
	"$(INTDIR)\bar.obj" \
	"$(INTDIR)\cockus.obj" \
	"$(INTDIR)\distribs.obj" \
	"$(INTDIR)\double.obj" \
	"$(INTDIR)\keyxfrm.obj" \
	"$(INTDIR)\sint.obj" \
	"$(INTDIR)\STRINGS.OBJ"

"$(OUTDIR)\External.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "External - Win32 Debug"

OUTDIR=.\External___Win32_Debug
INTDIR=.\External___Win32_Debug
# Begin Custom Macros
OutDir=.\External___Win32_Debug
# End Custom Macros

ALL : "$(OUTDIR)\External.exe"


CLEAN :
	-@erase "$(INTDIR)\bar.obj"
	-@erase "$(INTDIR)\cockus.obj"
	-@erase "$(INTDIR)\distribs.obj"
	-@erase "$(INTDIR)\double.obj"
	-@erase "$(INTDIR)\keyxfrm.obj"
	-@erase "$(INTDIR)\sint.obj"
	-@erase "$(INTDIR)\STRINGS.OBJ"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\External.exe"
	-@erase "$(OUTDIR)\External.ilk"
	-@erase "$(OUTDIR)\External.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /G6 /Gr /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /Fp"$(INTDIR)\External.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

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
BSC32_FLAGS=/nologo /o"$(OUTDIR)\External.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /incremental:yes /pdb:"$(OUTDIR)\External.pdb" /debug /machine:I386 /out:"$(OUTDIR)\External.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\bar.obj" \
	"$(INTDIR)\cockus.obj" \
	"$(INTDIR)\distribs.obj" \
	"$(INTDIR)\double.obj" \
	"$(INTDIR)\keyxfrm.obj" \
	"$(INTDIR)\sint.obj" \
	"$(INTDIR)\STRINGS.OBJ"

"$(OUTDIR)\External.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("External.dep")
!INCLUDE "External.dep"
!ELSE 
!MESSAGE Warning: cannot find "External.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "External - Win32 Release" || "$(CFG)" == "External - Win32 Debug"
SOURCE=.\bar.c

"$(INTDIR)\bar.obj" : $(SOURCE) "$(INTDIR)"


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



!ENDIF 

