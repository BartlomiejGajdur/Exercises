clc;
clear;

V1 = readmatrix('dane.xlsx','Range','D2:E21');

k = size(V1);
P1 = [0, 0];
P2 = [0, 0];
G_MaxX = 0;
G_MinX = 0;
weight = 0.5;

for col = 1:k(1,2)
    P1(1,col) = V1(1,col);
    P2(1,col) = V1(2,col);
end

if P1(1) > P2(1)
    tempMaxX = P1(1);
    tempMinX = P2(1);
else
    tempMaxX = P2(1);
    tempMinX = P1(1);
end

if tempMaxX > G_MaxX
    G_MaxX = tempMaxX;
    G_MinX = tempMinX;
end

%middle point to tylko X.
middlePoint = (G_MinX+G_MaxX)/2;

%wyliczana jest pierwsza funkcja z taką samą dziedziną
[a,b] = calcFunc(P1,P2,G_MaxX, G_MinX);

%for punkty od 3 do końca tabeli V1
for nxtP = 3:k(1,1)
    pn = [V1(nxtP,1), V1(nxtP,2)];
    if pn(1) > G_MaxX
        G_MaxX = pn(1);
    end
    if pn(1) < G_MinX
        G_MinX = pn(1);
    end
    middlePoint = (G_MinX+G_MaxX)/2;
    calcNextFunc(a, b, weight, middlePoint, G_MaxX, G_MinX, pn)
end

function [a,b] = calcNextFunc(a, b, weight, middlePoint, G_MaxX, G_MinX, p)
    Point3Casted = [p(1), a*p(1)+b];
    plot(Point3Casted(1),Point3Casted(2),'o');
    WeightedPoint = [p(1), (p(2) - (Point3Casted(2))) * weight + Point3Casted(2)];
    %scatter(Point3Casted(1),Point3Casted(2));
    plot(WeightedPoint(1),WeightedPoint(2),'x');

    if p(1) > middlePoint
        NewPoint  = [G_MinX; a*G_MinX+b];
    else
        NewPoint = [G_MaxX; a*G_MaxX+b];
    end
    [a,b] = calcFunc(WeightedPoint,NewPoint,G_MaxX,G_MinX);
    %//////////////////////////////////////////////////////
end

function [a,b] = calcFunc(p1,p2,MaxX, MinX)
    
    arr1 = [p1(1),p1(2);p2(1),p2(2)];
    arr2 = [arr1(1,2);arr1(2,2)];
    arr1(1,2) = 1;
    arr1(2,2) = 1;
    
    arr3 = inv(arr1)*arr2;
    a = arr3(1,1);
    b = arr3(2,1);

    %dziedzina od G_MinX do G_MaxX
    realm = [MinX:0.1:MaxX];
    y = a*realm+b;

      plot(realm,y)
    grid on;
    hold on;
end