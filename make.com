$ WRITE SYS$OUTPUT "Commencing build of ircd-hybrid-7 for VMS..."
$ WRITE SYS$OUTPUT "Examining source directory..."
$
$! $Id$
$! Don't have to do this any more - we now depend on
$! bison/flex to build.
$! FILE_SIZE = "NOSUCHFILE"
$! FILE_SIZE = F$FILE_ATTRIBUTES("[.INCLUDE]SETUP.H", "KNOWN")
$! IF FILE_SIZE .EQS. "NOSUCHFILE"
$!  THEN 
$!   WRITE SYS$OUTPUT "Copying SETUP.H_VMS to SETUP.H"
$!   COPY [.INCLUDE]SETUP.H_VMS [.INCLUDE]SETUP.H
$! ENDIF
$
$! vms_crypt.c is now src/crypt.c ..
$! FILE_SIZE = "NOSUCHFILE"
$! FILE_SIZE = F$FILE_ATTRIBUTES("[.SRC]VMS_CRYPT.C", "KNOWN")
$! IF FILE_SIZE .EQS. "NOSUCHFILE"
$!  THEN 
$!   WRITE SYS$OUTPUT "Copying VMS parser and crypt files from contrib"
$!   COPY [.CONTRIB]VMS_CRYPT.C [.SRC]VMS_CRYPT.C
$!   COPY [.CONTRIB]VMS_LEX_YY.C [.SRC]VMS_LEX_YY.C
$!   COPY [.CONTRIB]VMS_Y_TAB.C [.SRC]VMS_Y_TAB.C
$!   COPY [.CONTRIB]VMS_Y_TAB.H [.SRC]VMS_Y_TAB.H
$! ENDIF
$
$ ON ERROR THEN GOTO ERREXIT
$
$ WRITE SYS$OUTPUT "Building in modules..."
$ SET DEF [.MODULES]
$ MMK
$ WRITE SYS$OUTPUT "Leaving directory modules..."
$ SET DEF [-]
$
$ WRITE SYS$OUTPUT "Building in adns..."
$ SET DEF [.ADNS]
$ MMK
$ WRITE SYS$OUTPUT "Leaving directory adns..."
$ SET DEF [-]

$ WRITE SYS$OUTPUT "Building in src..."
$ SET DEF [.SRC]
$ MMK
$ WRITE SYS$OUTPUT "Leaving directory src..."
$ SET DEF [-]
$
$ WRITE SYS$OUTPUT "Building in tools..."
$ SET DEF [.TOOLS]
$ MMK
$ WRITE SYS$OUTPUT "Leaving directory tools..."
$ SET DEF [-]
$
$ WRITE SYS$OUTPUT "Build of ircd-hybrid-7 for VMS complete!"
$ EXIT

$ ERREXIT:
$ WRITE SYS$OUTPUT "Build aborted due to error"
$ SET DEF [-]
