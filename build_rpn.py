# trash ass build script xd
import os
import time

try:
    os.remove('rpn_test.exe')
except:
    pass

includes = []
includes.append("include")
includes.append("include/rpn")

sources = []
sources.append("src/rpn")

link = []

flags = "-std=c++11 -Wall -Wextra -Wfatal-errors -g"

compiler = "g++"

output = "test_rpn.exe"

include_str = ""
for directory in includes:
    include_str += f"-I\"{directory}/\" "

sources_str = ""
for src in sources:
    for _file in os.listdir(src):
        if (not os.path.isdir(f"{src}/{_file} ")):
            sources_str += f"{src}/{_file} "

link_str = ""
for l in link:
    sources_str += f"-l{l} "

cmd = f"{compiler} {flags} {include_str} -o {output} test_rpn.cpp {sources_str}"
print(cmd)
os.system(cmd)
t1 = time.time()
os.system(cmd)
t2 = time.time()

print("Operation time Elapsed:", f'{t2 - t1:.2f}', "seconds")