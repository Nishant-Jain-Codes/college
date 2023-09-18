def puntuationRemove(given):
    puntuations=[',','.','!',':',"'",'"',';','?','/','-']
    chars = [x for x in given if x not in puntuations]
    answer = ''.join(chars)
    return answer
given = input("enter input string\n")
print(f"'{puntuationRemove(given)}'\n is the removed string" )