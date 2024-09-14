#!/bin/bash

# 定义测试文件列表

file_pattern="input[0-9][0-9]"

# 使用文件名扩展功能（globbing）来匹配文件
test_files=( $file_pattern )
# 检查是否找到了匹配的文件
if [ ${#test_files[@]} -eq 0 ]; then
  echo "No files matching the pattern '$file_pattern' found."
  exit 1
fi

error_file=()
# 循环遍历匹配的文件
for inputfile in "${test_files[@]}"; do
  echo "Running ./scanner with $inputfile"
  ./scanner "$inputfile"
  
  # 检查命令是否成功执行
  if [ $? -ne 0 ]; then
    echo "Error running ./scanner with $inputfile"
    error_file+=( "$inputfile" )
  fi
done

# 检查是否有未正常运行的文件
if [ ${#error_file[@]} -gt 0 ]; then
  echo "The following files did not run successfully:"
  for error in "${error_file[@]}"; do
    echo "  - $error"
  done
else
  echo "All tests completed successfully."
fi
