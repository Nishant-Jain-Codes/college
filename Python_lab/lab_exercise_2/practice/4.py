# 4. Shrinking Guest List
# You just found out that your new dinner table won't arrive in time for the dinner, and you have space for only two guests.
# Add a new line that prints a message saying that you can invite only two people for dinner.
# Use pop() to remove guests from your list one at a time until only two names remain in your list. 
# Each time you pop a name from your list, print a message to that person letting them know you're sorry you can't invite them to dinner.
# Print a message to each of the two people still on your list, letting them know they're still invited.
# Use del to remove the last two names from your list, so you have an empty list. 
# Print your list to make sure you actually have an empty list at the end of your program.

invitees = ['cbum' , 'khabib','david','joe','kai']

print('sorry but the party is cancelled :/ i can only treat 2 ')
while len(invitees)>2:
    print(invitees[0],'sorry but your invitation is cancelled')
    del invitees[0]

# output
# sorry but the party is cancelled :/ i can only treat 2 
# cbum sorry but your invitation is cancelled
# khabib sorry but your invitation is cancelled
# david sorry but your invitation is cancelled