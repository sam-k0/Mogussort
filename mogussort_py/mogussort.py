import random
import sys


class Mogus:
    def __init__(self):
        self.inputVec = []
        self.outputVec = []

    def addElement(self, e):
        self.inputVec.append(e)

    def getElement(self, pos):
        if pos >= len(self.outputVec):
            print("Accessing element out of vector")
            return -1
        return self.outputVec[pos]

    def mogussort(self):
        iterCount = 0
        loopCount = 0
        self.outputVec.clear()
        # Copy to temp
        tempInput = self.inputVec.copy()

        sorted = False
        votedMate = None

        while not sorted:
            iterCount += 1
            # Choose random position
            randpos = 0
            if len(tempInput) > 1:
                randpos = random.randint(0, len(tempInput) - 1)

            # Vote sussy crewmates
            votedMate = tempInput.pop(randpos)
            self.outputVec.append(votedMate)

            # Check if imposters are REALLY SUS?
            prev = float('-inf')
            for i in range(len(self.outputVec)):
                if prev > self.outputVec[i]:
                    # Sussy?
                    # Reset the temp vec
                    tempInput = self.inputVec.copy()
                    self.outputVec.clear()
                    sorted = False
                    loopCount += 1
                    break
                prev = self.outputVec[i]

            if not tempInput:
                sorted = True

        print(
            f"Finished sorting {len(self.inputVec)} elements in {iterCount} iterations ({loopCount} loops)")

    def print(self):
        print("Printing output:")
        print(",".join(str(e) for e in self.outputVec))

    def printVec(self, vec):
        print(",".join(str(e) for e in vec))


def main():
    sus = 0x1 << 16**9
    mogus = Mogus()

    # Get elements from user input
    while True:
        try:
            num_elements = int(input("Enter the number of elements to sort: "))
            break
        except ValueError:
            print("Invalid input. Please enter an integer.")

    for i in range(num_elements):
        while True:
            try:
                element = int(input(f"Enter element {i+1}: "))
                mogus.addElement(element)
                break
            except ValueError:
                print("Invalid input. Please enter an integer.")

    mogus.print()  # Prints "Printing output:\n"

    mogus.mogussort()  # Sorts the elements

    mogus.print()  # Prints the sorted elements

    # Get element position from user input
    input("press enter to exit")


if __name__ == "__main__":
    main()
