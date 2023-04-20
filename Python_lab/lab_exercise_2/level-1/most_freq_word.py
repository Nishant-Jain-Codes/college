#read a file and return most frequency word 
from collections import Counter
import os
path = os.path.join("/workspaces/codespaces-blank/college/Python_lab/lab_exercise_2/level-1/", "input.txt")
file = open(path, "r",encoding="utf-8")
content = file.read()
most_freq = Counter(content.split(" "))
maxFreq = -1;
maxFreqStr = ""
for word,freq in most_freq.items():
    if(freq>maxFreq):
        maxFreq=freq
        maxFreqStr=word
print('most freq word and its freq ',maxFreqStr,maxFreq)
file.close()