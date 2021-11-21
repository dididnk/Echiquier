
int RegeNSah(int ox, int oy, int regex, int regey)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && regey == oy - 1 && regex == ox - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && regex == ox && regey == oy - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < LONGUEUR && regex == ox + 1 && regey == oy - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox + 1 < LONGUEUR && regey == oy && regex == ox + 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox + 1 < LONGUEUR && oy + 1 < LONGUEUR && regey == oy + 1 && regex == ox + 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (oy + 1 < LONGUEUR && regey == oy + 1 && regex == ox && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < LONGUEUR && regex == ox - 1 && regey == oy + 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && regey == oy && regex == ox - 1 && board[regey][regex] >= 0)
	{
		return 1;
	}
	return 0;
}


