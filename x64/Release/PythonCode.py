import re
import string

# dictionary of items returned from readfile operation
# key: name of item, value: quantity of item
itemDictionary = {}


# Read contents of input file and populate itemDictionary object with key/value pairs
# representing item name and item count
def ReadFile():
    # Read file contents and store in temporary variable
    file = open("input.txt", "r")
    file_contents = file.read()
    file.close()

    # Create a temporary array for iteration purposes
    itemList = file_contents.splitlines()

    # Iterate through itemList and populate dictionary
    # if item exists in the dictionary as a key, increment its value
    for item in itemList:
        if item in itemDictionary:
            itemDictionary[item] += 1
        else:
            itemDictionary[item] = 1


# Read file, Print dictionary contents
def PrintItemFrequencies():
    ReadFile()

    for x, y in itemDictionary.items():
        print(f'{x}: {y}')


# Read file, fetch item specific in param and return its count (case-insensitive)
def GetItemCount(searchTerm):
    ReadFile()

    for item in itemDictionary:
        if item.lower() == searchTerm.lower():
            return itemDictionary[item]

    return 0


# Read input file and build new .dat file with counted items
def WriteToFile():
    ReadFile()

    # array used to store key/value pairs from itemDictoinary 
    itemFrequency = []
    
    # iterate through dictionary and populate array with key/value pairs, adding
    # line breaks for presentational purposes in dat file.
    for itemName, itemCount in itemDictionary.items():
        itemFrequency.append(itemName + " " + str(itemCount) + "\n")

    # Remove extra line break from last item in array
    itemFrequency[-1] = itemFrequency[-1][:-1]

    # join items in itemFrequency into a single string to write to file
    dataString = ''.join(itemFrequency)

    # write data to file
    file = open("frequency.dat", "w")
    file.write(dataString)
