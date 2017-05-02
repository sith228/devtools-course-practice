import os
import re

print('=======================================')
project_directory = os.path.dirname(os.path.dirname(os.getcwd())) + '/modules'
print('Search directory:')
print(project_directory)
pattern_filename = r'test\w+\.*'
pattern_testname = r'bugreport_([a-zA-Z]*)_([a-zA-Z]*)_'

# Buglist
lastname = []
negative = []
positive = []
total = []

for dirs, node, files in os.walk(project_directory):
    for file in files:
        if len(re.findall(pattern_filename, file)) != 0:
            path_test_file = dirs + '/' + file
            file_stream = open(path_test_file)
            for line in file_stream.readlines():
                result = re.findall(pattern_testname, line)
                for res in result:
                    if lastname.count(res[0]) == 0:
                        lastname.append(res[0])
                        positive.append(1)
                        negative.append(0)
                        total.append(1)
                    else:
                        index = lastname.index(res[0])
                        positive[index] = positive[index] + 1
                        total[index] = total[index] + 1

                    if lastname.count(res[1]) == 0:
                        lastname.append(res[1])
                        positive.append(0)
                        negative.append(1)
                        total.append(-1)
                    else:
                        index = lastname.index(res[1])
                        negative[index] = negative[index] + 1
                        total[index] = total[index] - 1

            file_stream.close()
print('=======================================')
print('Bugreport table')
print('=======================================')
print('{0:10} {1:6} {2:6} {3:6}'.format('Lastname','Positive','Negative','Total'))
print('=======================================')
for i in range(len(lastname)):
    print('{0:10} {1:6d} {2:6d} {3:6d}'.format(lastname[i], positive[i],negative[i],total[i]))
print('=======================================')
