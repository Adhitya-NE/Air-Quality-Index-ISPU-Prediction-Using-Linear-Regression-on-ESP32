#ifndef MODEL_REGRESI_H
#define MODEL_REGRESI_H

double score(double * input)
{
    return -1.09
           + input[0]*0.47
           + input[1]*0.46
           + input[2]*(-0.12)
           + input[3]*0.72
           + input[4]*0.50;
}

#endif