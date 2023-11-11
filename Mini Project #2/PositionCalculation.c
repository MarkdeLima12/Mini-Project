#include <stdio.h>
#include <math.h>
#define MAX 100

int userDistance(struct userPosition[MAX], int people)
{
    float distance[MAX]; // used to store the distance between the user and the other person.
    int user;
    int latitudeDif, longitudeDif, altitudeDif; // will be used to return the other person that is closest to the user.
    for (int k = 1; k <= people; k++)           // will cycle through the people.
                                                // This is supposed to take the values from a structure but I can't figure out how to do it...
                                                // If you can figure it out, go for it
    {
        latitudeDif = (userPosition.userlatitude[k] - userPosition.userlatitude[k]) * (userPosition.userlatitude - lat[k]);
        longitudeDif = (userPosition.userlongitude - longi[k]) * (userPosition.userlatitude - lat[k]);
        altitudeDif = (userPosition.useraltitude - alt[k]) * (userPosition.useraltitude - alt[k]);
        // will house the if statement and the equation.
        distance[k] = sqrt(latitudeDif + longitudeDif + altitudeDif);
        if (distance[k] < distance[k - 1])
        {
            user = k;
        }
    }

    return user;
}

struct userStats // this is the format of the structure I found online, feel free to update as needed.
{
    char userName[MAX];
    float userlatitude;
    float userlongitude;
    float useraltitude;
};
struct userStats userStats[MAX];

struct userStats getOtherUserLocation(int people)
{

    struct userStats location;
    FILE *fileRead = fopen("user_location.txt", "r"); // open the file for reading
    if (fileRead == NULL)
    {
        printf("Error: cannot open file\n");
        exit(1); // terminate the program with an error code
    }
    // scan the file for the user ID and the location
    int id;
    double lat, lon, alt;
    fscanf(fileRead, "%d\n%lf\n%lf\n%lf", &id, &lat, &lon, &alt);

    fclose(fileRead); // close the file
    // store the location in the global array
    userStats[people] = location;
    // return the location
    return location;
}

int main()
{
    struct userStats userStats[MAX] = {};
    int numPeople;

    float latitude[MAX], longitude[MAX], altitude[MAX];

    for (int i = 0; i < numPeople; i++)
    {
        userStats userStats[i] = getOtherUserLocation(numPeople);
    }
    int closestUser = userDistance(userStats, numPeople);

    // there will be more print statements after this to help with the layout.

    printf("The closest user to you is user %d with a position of %f, %f, %f.", closestUser, longitude[closestUser], latitude[closestUser], altitude[closestUser]);
}