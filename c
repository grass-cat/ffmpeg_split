output_filename=$(basename -- "$1" | sed "s/[' ]//g")
output_extension="${output_filename##*.}"
output_filename="${output_filename%.*}"
ffmpeg -i $1 -i $2 -i $3 -i $4 -filter_complex "[0:v]format=pix_fmts=yuv420p[v0];[1:v]format=pix_fmts=yuv420p[v1];[2:v]format=pix_fmts=yuv420p[v2];[3:v]format=pix_fmts=yuv420p[v3];[v0][0:a][v1][1:a][v2][2:a][v3][3:a]concat=n=4:v=1:a=1[outv][outa]" -map "[outv]" -map "[outa]" -c:v libx264 -c:a aac "$output_filename"_output.mp4
