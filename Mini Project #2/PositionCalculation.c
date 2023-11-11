#include <stdio.h>
#define MAX 13

int userDistance(float lat[], float longi[], float alt[], int people, User userPosition)
{
    int distance;                     // used to store the distance between the user and the other person.
    int user;                         // will be used to return the other person that is closest to the user.
    for (int k = 1; k <= people; k++) // will cycle through the people.
    {
        // will house the if statement and the equation.
    }

    return user;
}

typedef struct user_0 User;

void passByValue(User user0);

struct user_0 // this is the format of the structure I found online, feel free to update as needed.
{
    float userlatitude;
    float userlongitude;
    float useraltitude;
};

double getOtherUserLocation(float *longitude[], float *latitude[], float *altitude[], int people)
{
    for (int i = 1; i <= people; i++) // Starts at 1 so that when you print out the value of i,
                                      // it prints starting at 1
    {
        printf("Please enter the latitude of Person #%d: ", i);
        scanf("%f", &latitude[i]);

        printf("Please enter the longitude of Person #%d: ", i);
        scanf("%f", &longitude[i]);

        printf("Please enter the altitude of Person #%d: ", i);
        scanf("%f", &altitude[i]);
    }
}

int main()
{
    int numPeople;
    float latitude[MAX], longitude[MAX], altitude[MAX];
    printf("How many other people are there: ");
    scanf("%d", &numPeople);

    getOtherUserLocation(&longitude, &latitude, &altitude, numPeople);

    int closestUser = userDistance(latitude, longitude, altitude, numPeople, user_0);

    // there will be more print statements after this to help with the layout.
}