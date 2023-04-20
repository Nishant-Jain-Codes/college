# 3. You just found a bigger dinner table, so now more space is available.
# Think of three more guests to invite to dinner.
# Add a print statement to the end of your program informing people that you found a bigger dinner table.
# Use insert() to add one new guest to the beginning of your list.
# Use insert() to add one new guest to the middle of your list.
# Use append() to add one new guest to the end of your list.
# Print a new set of invitation messages, one for each person in your list


invitees = ['cbum' , 'khabib','david','joe','kai']
other_invitees = ['rahul','rohan','ram','lakshman','ran']

def send_invites():
    for inv in invitees:
        print(inv,'please come to my gym opening')
    return None

def check_rejections():
    return input('write your name to decline the invite :')

def manage_rejection(rejected):
    if(rejected not in invitees):
        print("thanks but you weren't invited")
    else:
        invitees.remove(rejected)
        invitees.insert(0,other_invitees[0])
        other_invitees.pop(0)
        send_invites()

print('hey we have a new table enter your names')
for i in range(3):
    invitees.insert(0,input('your name '))
send_invites()

# input/output
# hey we have a new table enter your names
# your name nishant
# your name rahul
# your name rohan
# rohan please come to my gym opening
# rahul please come to my gym opening
# nishant please come to my gym opening
# cbum please come to my gym opening
# khabib please come to my gym opening
# david please come to my gym opening
# joe please come to my gym opening
# kai please come to my gym opening