bool lemonadeChange(int N, vector<int> &bills) {

        int count5 = 0;

        int count10 =  0;

        for(int i = 0; i < bills.size(); i++){

            if(bills[i]==5)count5++;

            else if(bills[i]==10){

                if(count5>0)count5--;

                else return 0;

                count10++;

            }

            else if(bills[i]==20){

                if(count10>0 && count5>0){

                    count10--;

                    count5--;

                }

                else if(count5>=3 && count10<1){

                    count5-=3;

                }

                else return 0;

            }

        }

        

        return 1;

    }