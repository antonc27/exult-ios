; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

[Setup]
AppName=Exult Tools
AppVerName=Exult Tools Git
DefaultDirName={pf}\Exult\Tools
DefaultGroupName=Exult Tools
OutputBaseFilename=ExultTools
Compression=lzma
SolidCompression=true
InternalCompressLevel=max
AppendDefaultDirName=false
AllowNoIcons=true
ShowLanguageDialog=yes
OutputDir=.
DirExistsWarning=no
AlwaysUsePersonalGroup=true

[Files]
; NOTE: Don't use "Flags: ignoreversion" on any shared system files
Source: Tools\ucxt.exe; DestDir: {app}; Flags: ignoreversion
Source: Tools\data\bginclude.uc; DestDir: {app}\data\; Flags: ignoreversion
Source: Tools\data\events.data; DestDir: {app}\data\; Flags: ignoreversion
Source: Tools\data\flags.data; DestDir: {app}\data\; Flags: ignoreversion
Source: Tools\data\u7bgintrinsics.data; DestDir: {app}\data\; Flags: ignoreversion
Source: Tools\data\u7misc.data; DestDir: {app}\data\; Flags: ignoreversion
Source: Tools\data\u7opcodes.data; DestDir: {app}\data\; Flags: ignoreversion
Source: Tools\data\u7siintrinsics.data; DestDir: {app}\data\; Flags: ignoreversion
Source: Tools\data\u7sibetaintrinsics.data; DestDir: {app}\data\; Flags: ignoreversion
Source: Tools\tools\cmanip.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\expack.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\expack.txt; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\intrins1.txt; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\intrins2.txt; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\ipack.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\ipack.txt; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\libsmooth_randomize.dll; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\libsmooth_smooth.dll; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\libsmooth_stream.dll; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\mklink.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\mockup.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\rip.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\SDL.dll; DestDir: {app}\tools\
Source: Tools\tools\shp2pcx.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\shp2pcx.txt; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\smooth.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\splitshp.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\splitshp.txt; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\textpack.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\textpack.txt; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\u7bgflag.txt; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\u7siflag.txt; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\u7voice2syx.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\ucc.exe; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\ucformat.txt; DestDir: {app}\tools\; Flags: ignoreversion
Source: Tools\tools\wuc.exe; DestDir: {app}\tools\; Flags: ignoreversion

[Dirs]
Name: {app}\data
Name: {app}\tools
