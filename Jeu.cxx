// int TourN(int ancienX, int ancienY, int nouveauX, int nouveauY)
// {
//     for (int i = ancienX - 1; i <= 0; i--) // Côté gauche
//     {
//         if ( tableDeJeu[ancienY][i] <= 0 && ( nouveauX == i && nouveauY == ancienY ) )
//         {
//             return NOIR;
//         }
//         else if ( tableDeJeu[ancienY][i] != 0)
//         {
//             break;
//         }      
//     }
//     for (int i = ancienX - 1; i <= 0; i--) // Côté Haut
//     {
//         if ( tableDeJeu[i][ancienX] <= 0 && ( nouveauX == ancienX && nouveauY == i ) )
//         {
//             return NOIR;
//         }
//         else if ( tableDeJeu[i][ancienX] != 0)
//         {
//             break;
//         }      
//     }
//     for (int i = ancienX + 1; i <= LONGUEUR; i++)
//     {
//         if ( (tableDeJeu[ancienY][i] <= 0) && (nouveauY == ancienY && nouveauX ==i) )
//         {
//             return 1;
//         }
//         else if ( tableDeJeu[ancienY][i] != 0)
//         {
//             break;
//         }
//     }
//     for (int i = ancienX + 1; i <= LONGUEUR; i++)
//     {
//         if ( (tableDeJeu[i][ancienX] <= 0) && (nouveauY == 1 && nouveauX == ancienX) )
//         {
//             return 1;
//         }
//         else if ( tableDeJeu[i][ancienX] != 0)
//         {
//             break;
//         }
//     }    
//     return  BLANC;
// }
