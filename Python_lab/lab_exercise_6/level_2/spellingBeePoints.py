def find_correct(spellings):
    correct = 0
    almostCorrect = 0
    incorrect = 0
    for user,dicitionary  in spellings.items():
        user = user.lower()
        dicitionary = dicitionary.lower()
        if(len(user) != len(dicitionary)):
            incorrect += 1
            continue
        mismatch = 0
        for i in range(len(user)):
            if user[i] != dicitionary[i]:
                mismatch += 1
        if(mismatch == 0):
            correct += 1
        elif(mismatch <= 2):
            almostCorrect += 1
        else:
            incorrect += 1
    return [correct, almostCorrect, incorrect]

spellings ={
    'Hellow': 'hello',
    'wrolD': 'world',
    'compter': 'computer',
    'meme': 'meme',
    'helLO': 'hello',
}
answer = []
answer = find_correct(spellings)
print(f"correct spellings are {answer[0]}")
print(f"Almost correct spellings are {answer[1]}")
print(f"incorrect spellings are {answer[2]}")
