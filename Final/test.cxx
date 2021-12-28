
for (int i = 0; i < LONGUEUR; i++)
{
    for (int j = 0; j < LONGUEUR; j++)
    {
        if (nullptr != m_cases[ (i - 1) + (j - 1) * 8] )
        {
            if (m_cases[ (i - 1) + (j - 1) * 8]  == PION_NOIR)
            {
                imgPionNoir.setPosition(j * taille, i * taille);
                window.draw(imgPionNoir);
            }
            if (m_cases[ (i - 1) + (j - 1) * 8] == PION_BLANC)
            {
                imgPionBlanc.setPosition(j * taille, i * taille);
                window.draw(imgPionBlanc);
            }
            if (m_cases[ (i - 1) + (j - 1) * 8] == TOUR_NOIR)
            {
                imgTourNoir.setPosition(j * taille, i * taille);
                window.draw(imgTourNoir);

            }
            if (m_cases[ (i - 1) + (j - 1) * 8] == TOUR_BLANC)
            {
                imgTourBlanc.setPosition(j * taille, i * taille);
                window.draw(imgTourBlanc);

            }
            if (m_cases[ (i - 1) + (j - 1) * 8] == CHEVAL_BLANC)
            {
                imgChevalBlanc.setPosition(j * taille, i * taille);
                window.draw(imgChevalBlanc);
            }
            if (m_cases[ (i - 1) + (j - 1) * 8] == CHEVAL_NOIR)
            {
                imgChevalNoir.setPosition(j * taille, i * taille);
                window.draw(imgChevalNoir);
            }
            if (m_cases[ (i - 1) + (j - 1) * 8] == FOU_NOIR)
            {
                imgFouNoir.setPosition(j * taille, i * taille);
                window.draw(imgFouNoir);
            }
            if (m_cases[ (i - 1) + (j - 1) * 8] == FOU_BLANC)
            {
                imgFouBlanc.setPosition(j * taille, i * taille);
                window.draw(imgFouBlanc);
            }
            if (m_cases[ (i - 1) + (j - 1) * 8] == REINE_BLANC)
            {
                imgReineBlanc.setPosition(j * taille, i * taille);
                window.draw(imgReineBlanc);
            }
            if (m_cases[ (i - 1) + (j - 1) * 8] == REINE_NOIR)
            {
                imgReineNoir.setPosition(j * taille, i * taille);
                window.draw(imgReineNoir);
            }
            if (m_cases[ (i - 1) + (j - 1) * 8] == ROI_NOIR)
            {
                imgRoiNoir.setPosition(j * taille, i * taille);
                window.draw(imgRoiNoir);
            }
            if (m_cases[ (i - 1) + (j - 1) * 8] == ROI_BLANC)
            {
                imgRoiBlanc.setPosition(j * taille, i * taille);
                window.draw(imgRoiBlanc);
            }
        }
    }
}
