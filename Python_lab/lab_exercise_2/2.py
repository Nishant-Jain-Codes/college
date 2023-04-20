# 2. Start with your program from Exercise 1. You just heard that one of your guests can't make the dinner,
# so you Modify your list,
# replacing the name of the guest who can't make it with the name of the new person you are inviting.
# Add a print statement at the end of your program stating the name of the guest who can't make it.
# Print a second set of invitation messages, one for each person who is still in your list.
# need to send out a new set of invitations. You'll have to think of someone else to invite.

invitees = ['cbum' , 'khabib','david','joe','kai']
other_invitees = ['rahul','rohan','ram','lakshman','ran']

def send_invites():
    for i in invitees:
        print(i,'please come to my gym opening')

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

manage_rejection(check_rejections())

#input output 

# write your name to decline the invite :cbum
# rahul please come to my gym opening
# khabib please come to my gym opening
# david please come to my gym opening
# joe please come to my gym opening
# kai please come to my gym opening
