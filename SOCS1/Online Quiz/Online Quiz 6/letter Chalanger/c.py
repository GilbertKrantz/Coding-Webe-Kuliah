
vocalCount = 0
consonantCount = 0

vocal = ['a', 'i', 'u', 'e', 'o']
consonant = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z']
letter = input()

for char in vocal :
    if char in letter :
        vocalCount += 1

for char in consonant :
    if char in letter :
        consonantCount += 1
        
print("Vocal: {}".format(vocalCount), end="\n")
print("Consonant: {}".format(consonantCount), end="\n")
        