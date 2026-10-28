#include <iostream>
#include <string>
using namespace std;

struct student
{
    int recordId = -1;
    string recordName;
    float gradePoint;
};

int tableSize = 11;
student studentTable[1000];
int slotStatus[1000] = {0};
int collisionCount = 0;

int calculateHash(int lookupKey, int iteration)
{
    int secondaryPrime = 7;
    int primaryHash = lookupKey % tableSize;
    int secondaryHash = secondaryPrime - (lookupKey % secondaryPrime);
    return (primaryHash + iteration * secondaryHash) % tableSize;
}

void insertRecord(struct student currentRecord)
{
    int iteration = 0;
    while (iteration < tableSize)
    {
        int slotIndex = calculateHash(currentRecord.recordId, iteration);
        if (slotStatus[slotIndex] != 1)
        {
            studentTable[slotIndex] = currentRecord;
            slotStatus[slotIndex] = 1;
            return;
        }
        else
        {
            iteration++;
            collisionCount++;
        }
    }
    cout << "Could not insert: " << currentRecord.recordId << endl;
}

int main()
{
    int recordId[7] = {19, 34, 47, 62, 75, 88, 11};
    string recordName[7] = {"A", "B", "C", "D", "E", "F", "G"};
    float gradePoint[7] = {3.80, 3.45, 3.90, 3.10, 3.55, 3.70, 3.25};

    for (int iteration = 0; iteration < 7; iteration++)
    {
        student currentRecord;
        currentRecord.recordId = recordId[iteration];
        currentRecord.recordName = recordName[iteration];
        currentRecord.gradePoint = gradePoint[iteration];
        insertRecord(currentRecord);
    }

    cout << "Total collisions: " << collisionCount << endl;
    return 0;
}
