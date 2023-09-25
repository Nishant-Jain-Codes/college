import random
playing = True
error = 0
def wordsInput():
    words = [x.lower() for x in input("enter all the words\n").split()]
    return words

def setInititalState(words):
    charFound = []
    word =  random.choice(words)
    return [charFound,word]
def handleCorrectInput(charFound,word):
    printCurrentState(charFound,word) 
    if len(charFound) == len(set(word)):
        print("YOU WON!!!!")
        global playing 
        playing = False
               
def printCurrentState(charFound,word):
    for x in word:
        if x in charFound:
            print(x,end='')
        else:
            print('_',end='')
    print()
def handleInput(charFound,word):
    play = input("guess the character ").lower()
    if play in word:
        charFound.append(play)
        handleCorrectInput(charFound,word)
    else:
        global error
        error +=1
        hngman ="HANGMAN"
        i=0
        print("WRONG -> ",end="")
        while(i<error):
            print(hngman[i],end="")
            i+=1
        if error == len("HANGMAN"):
            global playing
            playing = False
            print("GAME OVER!!!!")
            print(word,"WAS the word")
        print()
words = wordsInput()
[charFound,word] = setInititalState(words)
while(playing):
    handleInput(charFound,word)

