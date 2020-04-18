@echo off
FOR /F "tokens=*" %%G IN ('dir /b working_directory/downloaded_video.*') DO ^
ffmpeg -i %%G -c:v libx264 -crf %3 -preset ultrafast -c:a aac -strict experimental -b:a 192k -ss %1 -to %2 -ac 2 "working_directory/%4.mp4"