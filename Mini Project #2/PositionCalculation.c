#include <stdio.h>

double distance(double lat1, double lat2, double long1, double long2, double alt1, double alt2)
{
}

int main()
{
    int numPeople;
    float latitude[], longitude[], altitude[];
    printf("How many people are there: ");
    scanf("%d", &numPeople);

    for (int i = 1; i <= numPeople; i++)
    {
        printf("Please enter the latitude of Person #%f: ", i);
        scanf("%f", &latitude[i]);

        printf("Please enter the longitude of Person #%f: ", i);
        scanf("%f", &longitude[i]);

        printf("Please enter the altitude of Person #%f: ", i);
        scanf("%f", &altitude[i]);
    }
}