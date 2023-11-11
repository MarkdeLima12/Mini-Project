#include <stdio.h>
#define MAX 13

int distance(float lat[], float longi[], float alt[], int people)
{
    int distance;
    int user;
    for (int k = 1; k <= people; k++)
    {
    }

    return user;
}

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
    struct user_0
    {
        float userlatitude;
        float userlongitude;
        float useraltitude;
    };

    int numPeople;
    float latitude[MAX], longitude[MAX], altitude[MAX];
    printf("How many other people are there: ");
    scanf("%d", &numPeople);

    getOtherUserLocation(&longitude, &latitude, &altitude, numPeople);
}