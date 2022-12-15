dollarsum = 0;
        boostersum = beginbooster();
        begin();
        boosterchoose(&speedboosteropen,&priceboosteropen,&areaboosteropen);
        if(speedbooster == 0){
            speedboosteropen = 0;
        } 
        if(pricebooster == 0){
            priceboosteropen = 0;
        }
        if(areabooster == 0){
            areaboosteropen = 0;
        }
        actions(isc,ipc);
        for(int i=0;i<4;i++){
            actionsdo(i,speedboosteropen,priceboosteropen,areaboosteropen);
        }
        if(speedboosteropen == 2){
            speedboosteropen = 1;
            speedbooster -= 1;
            for(int i=0;i<boostersum;i++){
                if(boosterqueue[i] == 1){
                    temp = i;
                }

            }
            for(int i=temp;i<boostersum-1;i++){
                boosterqueue[i] = boosterqueue[i+1];
            }
            boostersum--;
        }
        if(priceboosteropen == 2){
            priceboosteropen = 1;
            pricebooster -= 1;
            for(int i=0;i<boostersum;i++){
                if(boosterqueue[i] == 2){
                    temp = i;
                }

            }
            for(int i=temp;i<boostersum-1;i++){
                boosterqueue[i] = boosterqueue[i+1];
            }
            boostersum--;
        }
        areasitutaion[4] = 5;
        areasitutaion[5] = 6;
        printf("Well done, you earn $%d today.\n",dollarsum);
        areacheck(speedboosteropen,priceboosteropen,areaboosteropen);