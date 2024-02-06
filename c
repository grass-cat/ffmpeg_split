output_filename=$(basename -- "$1" | sed "s/[' ]//g")
output_extension="${output_filename##*.}"
output_filename="${output_filename%.*}"
ffmpeg -i $1 -i $2 -i $3 -i $4 -filter_complex "[0:v][0:a][1:v][1:a][2:v][2:a][3:v][3:a]concat=n=4:v=1:a=1[outv][outa]" -map "[outv]" -map "[outa]" "$output_filename"_output.$output_extension
