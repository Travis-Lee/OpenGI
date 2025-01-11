echo "delete origin spv"
rm -rf *.spv
/usr/local/bin/glslc shader.comp -o shader.comp.spv
find ./ -name "*spv"
echo "create new spv file end!"
