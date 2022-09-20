#include<stdio.h>

int main()

{

    printf("\n\n"); /*space in terminal*/
    int a[3][7][7]; /*array to store the points of three graphs- demand curve, supply curve before      imposing tax and supply curve after imposing tax */

    /*Storing points for demand curve*/

    a[0][0][0]=7000;

    a[0][0][1]=0;

    a[0][1][0]=6000;

    a[0][1][1]=10;

    a[0][2][0]=5000;

    a[0][2][1]=20;

    a[0][3][0]=4000;

    a[0][3][1]=30;

    a[0][4][0]=3000;

    a[0][4][1]=40;

    a[0][5][0]=2000;

    a[0][5][1]=50;

    a[0][6][0]=1000;

    a[0][6][1]=60;

    /*Storing points for supply curve before imposing tax*/

    a[1][0][0]=1000;

    a[1][0][1]=0;

    a[1][1][0]=2000;

    a[1][1][1]=10;

    a[1][2][0]=3000;

    a[1][2][1]=20;

    a[1][3][0]=4000;

    a[1][3][1]=30;

    a[1][4][0]=5000;

    a[1][4][1]=40;

    a[1][5][0]=6000;

    a[1][5][1]=50;

    a[1][6][0]=7000;

    a[1][6][1]=60;

    /*Storing points for supply curve after imposing tax*/

    a[2][0][0]=3000;

    a[2][0][1]=0;

    a[2][1][0]=4000;

    a[2][1][1]=10;

    a[2][2][0]=5000;

    a[2][2][1]=20;

    a[2][3][0]=6000;

    a[2][3][1]=30;

    a[2][4][0]=7000;

    a[2][4][1]=40;

    int m[3];

    int y_differ,x_differ;

    /*Finding the gradient for every slope*/

    for(int i=0;i<3;i++)

    {

        y_differ=a[i][0][0]-a[i][4][0];

        x_differ=a[i][0][1]-a[i][4][1];

        m[i]=y_differ/x_differ;

    }

    /*

    m[0]=(-100) Gradient of demand curve

    m[1]=100 Gradient of supply curve before imposing tax

    m[2]=100 Gradient of supply curve after imposing tax

    */

    /*

    Finding the initial equilibrium point (Equilibrium before imposing tax)

    Initial quantity of supply and demand is

    x = (c2 - c1) / (m1 - m2) where c1 and c2 are intercepts of graph

    */

    int x_initial;

    int y_initial;

    int x_new;

    int y_new;

    int y_receiving;

    printf("Equilibrium point before imposing tax:\n");

    x_initial=(a[1][0][0]-a[0][0][0])/(m[0]-m[1]);

    printf("Initial equilibrium quantity is %d\n",x_initial);

    /*

    x= (7000-1000)/ (100-(-100))

    x=6000/200

    x=30

    */

    /*

    Initial equilibrium price is

    y=mx+c

    */

    y_initial=m[0]*x_initial+a[0][0][0];

    printf("Initial equilibrium price is Rs %d\n\n",y_initial);

    printf("Equilibrium point after imposing tax:\n");

    /*

    Finding the new equilibrium point (Equilibrium after imposing tax)

    New quantity of supply and demand is

    x = (c2 - c1) / (m1 - m2) where c1 and c2 are intercepts of graph

    */

    x_new=(a[2][0][0]-a[0][0][0])/(m[0]-m[2]);

    printf("New equilibrium quantity is %d\n",x_new);

    /*

    New equilibrium price is

    y=mx+c

    */

    y_new=m[0]*x_new+a[0][0][0];

    printf("New equilibrium price is Rs %d\n\n",y_new);

    printf("Tax borne by consumer:\n");

    int consumer=y_new-y_initial;

    printf("Rs %d per unit\n",consumer);

    printf("(It is the difference between Price now they are paying and Initial equilibrium price)\n\n");

    /*

    Price consumers get before tax= Rs 4000

    Price consumers get after tax = Rs 5000

    So, tax borne by consumer per unit is =

    Rs 5000-Rs4000=Rs1000


    */

    printf("Total tax amount by consumer:\n");

    int total_consumer=consumer*x_new;

    printf("Rs %d\n",total_consumer);

    printf("(Tax paid by consumer for unit quantity * New equilibrium quantity)\n\n");

    /*

    Total tax borne by consumer is =

    =Tax per unit * Quantity(at new equilibrium)

    = Rs 1000*20

    =Rs 20,000

    */

    y_receiving=m[1]*x_new+1000;

    printf("Tax borne by supplier:\n");

    int supplier=y_initial-y_receiving;

    printf("Rs %d per unit\n",supplier);

    printf("(It is the difference between Initial equilibrium price and price they are receiving now)\n\n");

    /*

    Price now they are receiving = Rs 3000

    Equilibrium price before imposition of tax = RS 4000

    So, tax borne by supplier per unit is =

    Rs 4000-Rs3000=Rs1000

    */

    printf("Total tax amount by supplier:\n");

    int total_supplier=supplier*x_new;

    printf("Rs %d\n",total_supplier);

    printf("(Tax paid by supplier for unit quantity * New equilibrium quantity)\n\n");

    /*

    Total tax borne by supplier is =

    =Tax per unit * Quantity(at new equilibrium)

    = Rs 1000*20

    =Rs 20,000


    */

    printf("Total tax revenue for government:\n");

    printf("Rs %d\n",total_consumer+total_supplier);

    printf("(It is the summation of tax borne by consumer and supplier)\n\n");

    /*

    Total tax revenue = Tax borne by consumer + Tax borne by supplier

    = Rs 20,000 + Rs 20,000

    = Rs 40,000

    */

    printf("Consumer surplus after imposition of tax is:\n");

    int consumer_surplus=0.5*(a[0][0][0]-y_new)*x_new;

    printf("%d\n\n",consumer_surplus);

    /*

    New consumer surplus = Area of triangle

    = 0.5*(7000-5000) *20

    = 20,000


    */

    printf("producer surplus after imposition of tax is:\n");

    int producer_surplus=0.5*(a[1][0][0]-y_receiving)*x_new;

    printf("%d\n\n",consumer_surplus);

    /*

    New producer surplus = Area of triangle

    = 0.5*(3000-1000) *20

    = 20,000

    */

    printf("Dead weight loss\n");

    int dead_weight_loss=0.5*(x_initial-x_new)*(y_new-y_receiving);

    printf("Rs %d\n\n",dead_weight_loss);

    char answer;

    printf("Do you want to find cross elasticity of demand for any objects?");

    scanf("%c",&answer);

    int initial_demand;

    int new_demand;

    float cross_elasticity;

    char rough;

    while(answer=='y'||answer=='Y')

    {

        printf("Enter initial quantity of demand:- ");

        scanf("%d",&initial_demand);

        printf("Enter new quantity of demand after change in price of rice:- ");

        scanf("%d",&new_demand);

        cross_elasticity=(float)(new_demand-initial_demand)/(y_new-y_initial);

        printf("Cross elasticity demand for the rice is %f\n", cross_elasticity);

        if(cross_elasticity>0)

        {

            printf("Substitute goods\n\n");

        }

        else

        {

            printf("Complementary goods\n\n");

        }

        printf("Do you want to find cross elasticity of demand for any objects?");

        scanf("%c%c",&rough,&answer);

    }

    return 0;
}

