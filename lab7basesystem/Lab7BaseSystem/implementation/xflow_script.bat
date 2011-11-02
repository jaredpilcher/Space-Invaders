@ECHO OFF
@REM ###########################################
@REM # Script file to run the flow 
@REM # 
@REM ###########################################
@REM #
@REM # Command line for ngdbuild
@REM #
ngdbuild -p xc2vp30ff896-7 -nt timestamp -bm system.bmm "D:/Put_Your_Temp_Files_Here/space_invaders/lab7basesystem/Lab7BaseSystem/implementation/system.ngc" -uc system.ucf system.ngd 

