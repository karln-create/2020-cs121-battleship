#include "root.h"


void sort_merge(char unsorted[], int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;

	sort_merge(unsorted, left, mid);
	sort_merge(unsorted, mid + 1, right);

	int marker_L = left, marker_R = mid + 1,
		k;

	int* temp_arr = malloc(sizeof(int) * MAX_BOARD_DIM);

	for (k = left; k <= right; ++k)
	{
		if (marker_L == mid + 1)
		{
			temp_arr[k] = unsorted[marker_R];
			++marker_R;
		}
		else if (marker_R == right + 1)
		{
			temp_arr[k] = unsorted[marker_L];
			++marker_L;
		}
		else if (unsorted[marker_L] < unsorted[marker_R])
		{
			temp_arr[k] = unsorted[marker_L];
			++marker_L;
		}
		else
		{
			temp_arr[k] = unsorted[marker_R];
			++marker_R;
		}
	}

	for (k = left; k <= right; ++k)
		unsorted[k] = temp_arr[k];

	free(temp_arr);
}

