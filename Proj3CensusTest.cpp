//For memory leak detection, use valgrind on Linux/Mac, and use crtdbg on Win32
/*
#ifdef _WIN32
	#define _CRTDBG_MAP_ALLOC
	#include <cstdlib>
	#include <crtdbg.h>
#endif // _WIN32
*/


#include <vector>
#include <stdlib.h>
#include "Int4MMH.h"
#include "CensusCity.h"
#include "MMHeap.h"
#include "QHeap.h"

void test1()
{
	// Testing small cases

	MMHeap<Int4MMH>* mmH = new MMHeap<Int4MMH>(30);

	mmH->insert(new Int4MMH(18));
	mmH->insert(new Int4MMH(94));
	mmH->insert(new Int4MMH(74));
	mmH->dump();
	mmH->deleteMax();
	mmH->dump();

	delete mmH;

	mmH = new MMHeap<Int4MMH>(90);

	// Figure 6->57 from Weiss 3/e 
	mmH->insert(new Int4MMH(6));
	mmH->insert(new Int4MMH(81));
	mmH->insert(new Int4MMH(87));
	mmH->insert(new Int4MMH(14));
	mmH->insert(new Int4MMH(17));
	mmH->insert(new Int4MMH(12));
	mmH->insert(new Int4MMH(28));
	mmH->insert(new Int4MMH(71));
	mmH->insert(new Int4MMH(25));
	mmH->insert(new Int4MMH(80));
	mmH->insert(new Int4MMH(20));
	mmH->insert(new Int4MMH(52));
	mmH->insert(new Int4MMH(78));
	mmH->insert(new Int4MMH(31));
	mmH->insert(new Int4MMH(42));
	mmH->insert(new Int4MMH(31));
	mmH->insert(new Int4MMH(59));
	mmH->insert(new Int4MMH(16));
	mmH->insert(new Int4MMH(24));
	mmH->insert(new Int4MMH(79));
	mmH->insert(new Int4MMH(63));
	mmH->insert(new Int4MMH(18));
	mmH->insert(new Int4MMH(19));
	mmH->insert(new Int4MMH(32));
	mmH->insert(new Int4MMH(13));
	mmH->insert(new Int4MMH(15));
	mmH->insert(new Int4MMH(48));

	mmH->dump();

	mmH->insert(new Int4MMH(53));
	mmH->insert(new Int4MMH(57));
	mmH->insert(new Int4MMH(13));
	mmH->insert(new Int4MMH(12));
	mmH->insert(new Int4MMH(9));
	mmH->insert(new Int4MMH(10));

	mmH->dump();

	mmH->deleteMin();
	mmH->deleteMin();
	mmH->deleteMin();

	mmH->deleteMax();
	mmH->deleteMax();
	mmH->deleteMax();

	mmH->dump();

	delete mmH;
}

void test2()
{
	QHeap<Int4MMH>* q = new QHeap<Int4MMH>(2000);
	for (int i = 1; i <= 60; i++)
		q->insert(new Int4MMH(rand() % 100));
	q->dump();
	delete q;
}

void test3()
{
	// California cities 2010 Census population
	std::vector<int> CA_2010{
	   73812, 83089, 336265, 102372, 69135, 56364, 347483, 75390, 76616, 112580,
	   51481, 80530, 103340, 65201, 105328, 91714, 51200, 86187, 77983, 74799,
	   243916, 83301, 95631, 52154, 96455, 122067, 152374, 109960, 58302, 101123,
	   65622, 53041, 55544, 111772, 53683, 99478, 113475, 153015, 59518, 143911,
	   105321, 72203, 196069, 55313, 214089, 494665, 135161, 170883, 58829, 191719,
	   50073, 53967, 84293, 144186, 78657, 90173, 53104, 189992, 58114, 76036,
	   109673, 212375, 60239, 57065, 62979, 51821, 77264, 80048, 156633, 80968,
	   62134, 462257, 3792621, 69772, 61416, 67096, 77519, 78958, 66790, 93305,
	   201165, 62500, 60269, 193365, 74066, 103466, 76915, 58582, 85186, 105549,
	   51904, 390724, 167086, 163924, 136416, 197899, 152750, 64403, 54098, 137122,
	   68386, 57941, 62942, 63264, 50533, 70285, 149058, 54165, 64776, 165269,
	   89861, 68747, 66748, 76815, 99171, 103701, 303871, 56974, 53764, 118788,
	   466488, 150441, 209924, 106433, 63522, 1307402, 805235, 945942, 84950, 83781,
	   97207, 57713, 72148, 324528, 88410, 116468, 176320, 59946, 99553, 89736,
	   167815, 53413, 124237, 94396, 63632, 291707, 140081, 100097, 126683, 145438,
	   82922, 59278, 68549, 75540, 69516, 73732, 92428, 115942, 115903, 124442,
	   93834, 64173, 51199, 106098, 89701, 85331, 55468, 64234, 64925, 51367
	};


	// California cities 2011 estimated population
	std::vector<int> CA_2011{
	   74774, 83693, 341361, 104044, 70172, 56769, 352428, 75940, 77170, 113905,
	   52326, 81747, 104092, 65895, 106888, 92376, 52381, 86290, 79059, 75928,
	   247535, 84330, 96929, 52940, 97156, 124055, 155896, 111600, 59220, 102362,
	   66016, 53819, 55951, 112584, 54930, 100928, 114296, 154908, 60400, 146032,
	   106126, 73001, 199028, 56153, 216916, 501362, 137183, 173470, 59253, 193111,
	   50435, 54284, 84905, 146069, 80467, 91534, 53903, 192888, 58536, 77780,
	   110464, 215529, 61164, 57907, 63940, 53417, 78439, 80634, 157693, 82039,
	   63133, 465576, 3819702, 70257, 62219, 68254, 79312, 80232, 67804, 94721,
	   202751, 62954, 60707, 197838, 75235, 105857, 77867, 59369, 86484, 106309,
	   52456, 395817, 169569, 166390, 138409, 199943, 153867, 65412, 54492, 138101,
	   69967, 58453, 63400, 64294, 51302, 71215, 150119, 55023, 65606, 167721,
	   90138, 69752, 67233, 77745, 100662, 105380, 310651, 58324, 54154, 121767,
	   472178, 152994, 213012, 107514, 64491, 1326179, 812826, 967487, 86071, 85022,
	   98391, 58313, 73333, 329427, 89045, 118263, 177601, 60342, 100277, 90377,
	   169292, 54197, 125522, 95084, 64409, 296357, 142287, 102464, 127984, 146493,
	   84266, 60289, 69089, 76689, 70436, 74837, 93088, 116829, 117597, 126432,
	   95204, 65211, 51586, 106870, 91064, 85943, 55806, 65215, 65050, 52139
	};


	// California city names
	std::vector<std::string> CA_city{
	   "Alameda", "Alhambra", "Anaheim", "Antioch", "Apple Valley",
	   "Arcadia", "Bakersfield", "Baldwin Park", "Bellflower", "Berkeley",
	   "Brentwood", "Buena Park", "Burbank", "Camarillo", "Carlsbad",
	   "Carson", "Cathedral City", "Chico", "Chino", "Chino Hills",
	   "Chula Vista", "Citrus Heights", "Clovis", "Colton", "Compton",
	   "Concord", "Corona", "Costa Mesa", "Cupertino", "Daly City",
	   "Davis", "Delano", "Diamond Bar", "Downey", "Eastvale",
	   "El Cajon", "El Monte", "Elk Grove", "Encinitas", "Escondido",
	   "Fairfield", "Folsom", "Fontana", "Fountain Valley", "Fremont",
	   "Fresno", "Fullerton", "Garden Grove", "Gardena", "Glendale",
	   "Glendora", "Hanford", "Hawthorne", "Hayward", "Hemet",
	   "Hesperia", "Highland", "Huntington Beach", "Huntington Park", "Indio",
	   "Inglewood", "Irvine", "La Habra", "La Mesa", "Laguna Niguel",
	   "Lake Elsinore", "Lake Forest", "Lakewood", "Lancaster", "Livermore",
	   "Lodi", "Long Beach", "Los Angeles", "Lynwood", "Madera",
	   "Manteca", "Menifee", "Merced", "Milpitas", "Mission Viejo",
	   "Modesto", "Montebello", "Monterey Park", "Moreno Valley", "Mountain View",
	   "Murrieta", "Napa", "National City", "Newport Beach", "Norwalk",
	   "Novato", "Oakland", "Oceanside", "Ontario", "Orange",
	   "Oxnard", "Palmdale", "Palo Alto", "Paramount", "Pasadena",
	   "Perris", "Petaluma", "Pico Rivera", "Pittsburg", "Placentia",
	   "Pleasanton", "Pomona", "Porterville", "Rancho Cordova", "Rancho Cucamonga",
	   "Redding", "Redlands", "Redondo Beach", "Redwood City", "Rialto",
	   "Richmond", "Riverside", "Rocklin", "Rosemead", "Roseville",
	   "Sacramento", "Salinas", "San Bernardino", "San Buenaventura (Ventura)", "San Clemente",
	   "San Diego", "San Francisco", "San Jose", "San Leandro", "San Marcos",
	   "San Mateo", "San Rafael", "San Ramon", "Santa Ana", "Santa Barbara",
	   "Santa Clara", "Santa Clarita", "Santa Cruz", "Santa Maria", "Santa Monica",
	   "Santa Rosa", "Santee", "Simi Valley", "South Gate", "South San Francisco",
	   "Stockton", "Sunnyvale", "Temecula", "Thousand Oaks", "Torrance",
	   "Tracy", "Tulare", "Turlock", "Tustin", "Union City",
	   "Upland", "Vacaville", "Vallejo", "Victorville", "Visalia",
	   "Vista", "Walnut Creek", "Watsonville", "West Covina", "Westminster",
	   "Whittier", "Woodland", "Yorba Linda", "Yuba City", "Yucaipa"
	};


	// California state names. (OK this is a bit silly.)
	std::vector<std::string> CA_state{
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California",
	   "California", "California", "California", "California", "California"
	};

	// Other States 2010 Census population
	std::vector<int> OS_2010{
	   53380, 212237, 55683, 65496, 81619, 180105, 195111, 205764, 90468, 291826,
	   76238, 50876, 236123, 65870, 208453, 226721, 65275, 52527, 439041, 154065,
	   1445632, 217385, 117517, 161719, 520116, 93064, 58908, 73580, 86209, 67263,
	   193524, 62304, 55964, 69797, 106433, 325078, 97385, 55889, 100377, 416427,
	   600158, 143986, 58566, 92889, 142980, 86270, 66859, 106595, 118772, 106114,
	   144229, 60477, 80893, 124775, 60868, 51271, 73206, 129779, 85603, 122643,
	   110366, 55564, 70851, 601723, 84392, 68217, 49546, 154305, 107685, 52909,
	   121096, 91992, 61005, 75018, 60522, 85182, 165521, 62298, 124354, 224669,
	   140768, 60512, 821784, 55156, 59682, 97422, 77648, 66887, 53284, 76068,
	   87779, 399457, 107167, 122041, 58786, 57357, 56315, 238300, 103190, 75180,
	   154750, 51923, 84955, 99845, 56048, 164603, 53570, 51917, 244769, 84439,
	   181376, 60427, 335709, 56508, 99919, 65333, 77434, 57551, 115452, 420003,
	   195844, 189885, 76728, 91351, 56579, 88346, 93853, 136286, 51271, 54518,
	   66588, 337256, 205671, 56813, 75092, 81557, 54255, 75101, 197899, 56657,
	   76610, 73366, 81055, 2695598, 83891, 76122, 58364, 108188, 74486, 51895,
	   147433, 54167, 141853, 52497, 56690, 51878, 56767, 68557, 115007, 152871,
	   74227, 64784, 116250, 56703, 89078, 52894, 56129, 80405, 79191, 50949,
	   117429, 76794, 253691, 80294, 49791, 80830, 820445, 67140, 70085, 51969,
	   101168, 60785, 58965, 126326, 62230, 99685, 203433, 57637, 67862, 82684,
	   68406, 56609, 145786, 87643, 52281, 125872, 173372, 62209, 127473, 382368,
	   58067, 295803, 597337, 57265, 229493, 61315, 66702, 120623, 71993, 343829,
	   199311, 66194, 620961, 54727, 65239, 59933, 61209, 617594, 93810, 105162,
	   55298, 88857, 60879, 76377, 106519, 90329, 59450, 56173, 95072, 85146,
	   51251, 92271, 51755, 75754, 153060, 55874, 60632, 53743, 181045, 113934,
	   52347, 98153, 57774, 713777, 79740, 102434, 188040, 74262, 114297, 96942,
	   55224, 59515, 70995, 57236, 51508, 71739, 59715, 129699, 63131, 80980,
	   134056, 84094, 72125, 57186, 82893, 75781, 60306, 61476, 86265, 64206,
	   60797, 55954, 61567, 382578, 49734, 70576, 106769, 65842, 285068, 61961,
	   67793, 173514, 52575, 108500, 52158, 116830, 50150, 459787, 91364, 79329,
	   159498, 65794, 76780, 319294, 52575, 104170, 58505, 66788, 50137, 258379,
	   408958, 55274, 257729, 583756, 216961, 225221, 90264, 109565, 86494, 63024,
	   77344, 84136, 64270, 124969, 50005, 247597, 55181, 277140, 69781, 146199,
	   50814, 49808, 84913, 66455, 60724, 49708, 545852, 97618, 87521, 67947,
	   97856, 261310, 53891, 67292, 77062, 8175133, 50193, 210565, 66135, 145170,
	   50129, 62235, 56853, 195976, 83393, 49963, 135234, 57233, 731424, 79066,
	   228330, 200564, 71741, 269666, 84554, 104371, 70145, 403892, 57477, 106476,
	   229617, 61272, 105549, 52838, 199110, 73007, 296943, 396815, 787033, 141527,
	   54533, 62477, 56163, 52131, 64097, 81601, 60608, 287208, 66982, 98850,
	   81405, 96867, 54371, 55081, 110925, 579999, 391906, 50158, 89803, 76639,
	   54462, 156185, 105594, 91611, 74907, 583776, 154637, 59403, 118032, 74982,
	   101786, 59322, 1526006, 305704, 88082, 76089, 80387, 71148, 178042, 82672,
	   120083, 129272, 58409, 67843, 97471, 66154, 67956, 153888, 54613, 167674,
	   132929, 62487, 51372, 65211, 63152, 178874, 646889, 108755, 601222, 117063,
	   84246, 190695, 365438, 790390, 71802, 118296, 175023, 76201, 119097, 48937,
	   93857, 56207, 305215, 1197816, 113383, 49047, 77100, 649121, 51277, 64669,
	   741206, 116989, 226876, 175396, 64849, 2099451, 216290, 127921, 236091, 83560,
	   95290, 80455, 229573, 56368, 129877, 131117, 139824, 111147, 77058, 67358,
	   57740, 63343, 99940, 149043, 91252, 70400, 259841, 53818, 99223, 99887,
	   56199, 93200, 1327407, 78817, 66102, 96900, 62592, 124805, 104553, 67311,
	   82825, 88328, 112488, 186440, 87461, 50418, 72897, 58652, 103712, 129480,
	   139966, 222209, 137436, 75568, 180719, 242803, 95535, 204214, 97032, 84585,
	   437994, 70180, 122363, 80885, 103019, 89306, 73917, 92411, 58163, 60020,
	   59781, 54144, 90927, 608660, 53007, 208916, 89755, 198397, 161791, 91067,
	   51400, 72623, 65883, 104057, 63575, 99218, 51320, 233209, 594833, 66083,
	   78860, 70718, 60411, 55316, 59466
	};

	// Other states 2011 estimated population
	std::vector<int> OS_2011{
	   54566, 212413, 55902, 66010, 82003, 182956, 194914, 208182, 91605, 295570,
	   77518, 51649, 240101, 65914, 211951, 230482, 66309, 52935, 446518, 156637,
	   1469471, 221020, 119489, 164268, 525796, 94536, 60470, 75102, 87152, 68547,
	   195314, 62886, 57539, 71397, 107541, 332354, 98889, 57352, 102603, 426388,
	   619968, 146762, 58704, 94962, 144406, 87712, 68203, 107577, 121435, 107967,
	   145638, 60525, 81671, 124867, 60770, 51189, 73261, 129585, 86460, 123868,
	   110189, 55477, 71305, 617996, 85329, 68996, 50193, 157476, 107784, 53915,
	   123338, 93674, 61028, 76389, 61209, 85219, 168528, 63512, 125326, 229969,
	   143357, 61940, 827908, 55911, 61346, 98589, 77723, 68117, 54270, 76095,
	   89840, 408750, 109680, 124302, 60143, 57780, 56517, 243195, 103227, 76499,
	   157594, 52197, 86524, 101617, 56529, 166149, 53926, 52341, 244997, 85995,
	   182965, 61542, 346037, 57163, 101043, 66544, 77683, 59397, 116084, 432427,
	   196494, 194107, 79192, 91856, 57357, 91168, 96856, 139491, 51982, 56019,
	   68500, 340936, 210145, 57646, 76750, 82755, 54810, 75428, 199672, 56906,
	   77071, 73802, 81291, 2707120, 84261, 76096, 58617, 109104, 74785, 52124,
	   148402, 54403, 142773, 52772, 56937, 52104, 57016, 68858, 115234, 152222,
	   74550, 65066, 117076, 56965, 89426, 53238, 55957, 81381, 81564, 51320,
	   117825, 79127, 255824, 80221, 51584, 80757, 827609, 67947, 70080, 53515,
	   101081, 60961, 59042, 127905, 62466, 100802, 206599, 58234, 68947, 82967,
	   68653, 57909, 146453, 88727, 53678, 127907, 176185, 63219, 128188, 384445,
	   58894, 301569, 602011, 57605, 230139, 62745, 66715, 122130, 72475, 360740,
	   200975, 66363, 619493, 55232, 66169, 61045, 62334, 625087, 94316, 106038,
	   55333, 88962, 61351, 76976, 107584, 91040, 60071, 56738, 95183, 85945,
	   51653, 92909, 52459, 76519, 153155, 55940, 61181, 54116, 181631, 114925,
	   52093, 97144, 57186, 706585, 80258, 101558, 189815, 74743, 114605, 95958,
	   55583, 59887, 71452, 57607, 51230, 72201, 59798, 129880, 62489, 81508,
	   134243, 83239, 72833, 57584, 84057, 76853, 60828, 61904, 86277, 64765,
	   61657, 56443, 62440, 387753, 50435, 71561, 107890, 66169, 288448, 62787,
	   69220, 175561, 52749, 110438, 52145, 117213, 50559, 463202, 91668, 80519,
	   160660, 66598, 77185, 318069, 53264, 105636, 58950, 67290, 51319, 262341,
	   415068, 55439, 260068, 589317, 219020, 227511, 91195, 109830, 86704, 63722,
	   77283, 84269, 64365, 125660, 50545, 250323, 55444, 277540, 69893, 146427,
	   51093, 50085, 84899, 67187, 60952, 50260, 552804, 99665, 89320, 68642,
	   97660, 261025, 54088, 67780, 77606, 8244910, 50086, 210855, 66273, 145151,
	   50120, 62110, 57258, 197399, 84458, 50925, 139633, 58011, 751087, 80597,
	   233252, 203945, 72068, 273425, 86017, 105753, 70801, 416468, 57433, 108297,
	   232385, 62665, 107349, 52631, 198402, 72919, 296223, 393806, 797434, 142148,
	   54581, 62795, 56427, 51724, 64152, 80968, 60333, 286038, 66571, 100073,
	   82963, 98177, 55427, 56315, 113273, 591967, 396466, 50724, 91625, 77905,
	   54674, 156929, 107439, 93455, 75501, 593820, 156244, 59695, 119141, 75266,
	   101807, 60058, 1536471, 307484, 88414, 75995, 80392, 71153, 178053, 82361,
	   122689, 130591, 60379, 69357, 99727, 67423, 69200, 156592, 55055, 170136,
	   136231, 64317, 52349, 65187, 63815, 180761, 652050, 111327, 609644, 118117,
	   87473, 193675, 373698, 820611, 73322, 118548, 178430, 77321, 122640, 51283,
	   95142, 58973, 307953, 1223229, 117187, 50045, 79147, 665568, 52443, 67019,
	   758738, 121387, 231517, 179100, 66122, 2145146, 220702, 130018, 241935, 84856,
	   98737, 81336, 233740, 57627, 133742, 136067, 142674, 113931, 79368, 69774,
	   59590, 64780, 102106, 152281, 93305, 72513, 269776, 53937, 101742, 104664,
	   57463, 94544, 1359758, 81700, 67188, 98564, 63131, 126697, 103931, 68495,
	   83949, 90727, 115321, 189899, 89200, 51377, 74770, 59767, 105675, 131942,
	   144301, 225050, 136401, 76504, 179611, 242628, 95684, 205533, 96714, 84930,
	   442707, 71517, 124798, 81862, 104295, 91085, 76224, 120916, 58839, 60785,
	   63186, 55228, 92812, 620778, 54044, 210103, 90279, 200678, 164759, 92512,
	   51177, 73243, 66623, 105809, 63479, 99738, 51719, 236901, 597867, 66344,
	   78853, 70867, 60714, 55988, 60096
	};

	// Other states city names
	std::vector<std::string> OS_city{
	   "Auburn", "Birmingham", "Decatur", "Dothan", "Hoover",
	   "Huntsville", "Mobile", "Montgomery", "Tuscaloosa", "Anchorage",
	   "Avondale", "Buckeye", "Chandler", "Flagstaff", "Gilbert",
	   "Glendale", "Goodyear", "Lake Havasu City", "Mesa", "Peoria",
	   "Phoenix", "Scottsdale", "Surprise", "Tempe", "Tucson",
	   "Yuma", "Conway", "Fayetteville", "Fort Smith", "Jonesboro",
	   "Little Rock", "North Little Rock", "Rogers", "Springdale", "Arvada",
	   "Aurora", "Boulder", "Broomfield", "Centennial", "Colorado Springs",
	   "Denver", "Fort Collins", "Grand Junction", "Greeley", "Lakewood",
	   "Longmont", "Loveland", "Pueblo", "Thornton", "Westminster",
	   "Bridgeport", "Bristol", "Danbury", "Hartford", "Meriden",
	   "Milford", "New Britain", "New Haven", "Norwalk", "Stamford",
	   "Waterbury", "West Haven", "Wilmington", "Washington", "Boca Raton",
	   "Boynton Beach", "Bradenton", "Cape Coral", "Clearwater", "Coconut Creek",
	   "Coral Springs", "Davie", "Daytona Beach", "Deerfield Beach", "Delray Beach",
	   "Deltona", "Fort Lauderdale", "Fort Myers", "Gainesville", "Hialeah",
	   "Hollywood", "Homestead", "Jacksonville", "Jupiter", "Kissimmee",
	   "Lakeland", "Largo", "Lauderhill", "Margate", "Melbourne",
	   "Miami Beach", "Miami", "Miami Gardens", "Miramar", "North Miami",
	   "North Port", "Ocala", "Orlando", "Palm Bay", "Palm Coast",
	   "Pembroke Pines", "Pensacola", "Plantation", "Pompano Beach", "Port Orange",
	   "Port St. Lucie", "Sanford", "Sarasota", "St. Petersburg", "Sunrise",
	   "Tallahassee", "Tamarac", "Tampa", "Wellington", "West Palm Beach",
	   "Weston", "Albany", "Alpharetta", "Athens", "Atlanta",
	   "Augusta", "Columbus", "Johns Creek", "Macon", "Marietta",
	   "Roswell", "Sandy Springs", "Savannah", "Smyrna", "Valdosta",
	   "Warner Robins", "Urban Honolulu CDP", "Boise City", "Idaho Falls", "Meridian",
	   "Nampa", "Pocatello", "Arlington Heights", "Aurora", "Berwyn",
	   "Bloomington", "Bolingbrook", "Champaign", "Chicago", "Cicero",
	   "Decatur", "Des Plaines", "Elgin", "Evanston", "Hoffman Estates",
	   "Joliet", "Mount Prospect", "Naperville", "Normal", "Oak Lawn",
	   "Oak Park", "Orland Park", "Palatine", "Peoria", "Rockford",
	   "Schaumburg", "Skokie", "Springfield", "Tinley Park", "Waukegan",
	   "Wheaton", "Anderson", "Bloomington", "Carmel", "Elkhart",
	   "Evansville", "Fishers", "Fort Wayne", "Gary", "Greenwood",
	   "Hammond", "Indianapolis", "Lafayette", "Muncie", "Noblesville",
	   "South Bend", "Terre Haute", "Ames", "Cedar Rapids", "Council Bluffs",
	   "Davenport", "Des Moines", "Dubuque", "Iowa City", "Sioux City",
	   "Waterloo", "West Des Moines", "Kansas City", "Lawrence", "Manhattan",
	   "Olathe", "Overland Park", "Shawnee", "Topeka", "Wichita",
	   "Bowling Green", "Lexington-Fayette", "Louisville", "Owensboro", "Baton Rouge",
	   "Bossier City", "Kenner", "Lafayette", "Lake Charles", "New Orleans",
	   "Shreveport", "Portland", "Baltimore", "Bowie", "Frederick",
	   "Gaithersburg", "Rockville", "Boston", "Brockton", "Cambridge",
	   "Chicopee", "Fall River", "Haverhill", "Lawrence", "Lowell",
	   "Lynn", "Malden", "Medford", "New Bedford", "Newton",
	   "Peabody", "Quincy", "Revere", "Somerville", "Springfield",
	   "Taunton", "Waltham", "Weymouth Town", "Worcester", "Ann Arbor",
	   "Battle Creek", "Dearborn", "Dearborn Heights", "Detroit", "Farmington Hills",
	   "Flint", "Grand Rapids", "Kalamazoo", "Lansing", "Livonia",
	   "Novi", "Pontiac", "Rochester Hills", "Royal Oak", "Saginaw",
	   "Southfield", "St. Clair Shores", "Sterling Heights", "Taylor", "Troy",
	   "Warren", "Westland", "Wyoming", "Blaine", "Bloomington",
	   "Brooklyn Park", "Burnsville", "Coon Rapids", "Duluth", "Eagan",
	   "Eden Prairie", "Lakeville", "Maple Grove", "Minneapolis", "Minnetonka",
	   "Plymouth", "Rochester", "St. Cloud", "St. Paul", "Woodbury",
	   "Gulfport", "Jackson", "Blue Springs", "Columbia", "Florissant",
	   "Independence", "Joplin", "Kansas City", "Lee's Summit", "O'Fallon",
	   "Springfield", "St. Charles", "St. Joseph", "St. Louis", "St. Peters",
	   "Billings", "Great Falls", "Missoula", "Bellevue", "Lincoln",
	   "Omaha", "Carson City", "Henderson", "Las Vegas", "North Las Vegas",
	   "Reno", "Sparks", "Manchester", "Nashua", "Bayonne",
	   "Camden", "Clifton", "East Orange", "Elizabeth", "Hoboken",
	   "Jersey City", "New Brunswick", "Newark", "Passaic", "Paterson",
	   "Perth Amboy", "Plainfield", "Trenton", "Union City", "Vineland",
	   "West New York", "Albuquerque", "Las Cruces", "Rio Rancho", "Santa Fe",
	   "Albany", "Buffalo", "Hempstead", "Mount Vernon", "New Rochelle",
	   "New York", "Niagara Falls", "Rochester", "Schenectady", "Syracuse",
	   "Troy", "Utica", "White Plains", "Yonkers", "Asheville",
	   "Burlington", "Cary", "Chapel Hill", "Charlotte", "Concord",
	   "Durham", "Fayetteville", "Gastonia", "Greensboro", "Greenville",
	   "High Point", "Jacksonville", "Raleigh", "Rocky Mount", "Wilmington",
	   "Winston-Salem", "Bismarck", "Fargo", "Grand Forks", "Akron",
	   "Canton", "Cincinnati", "Cleveland", "Columbus", "Dayton",
	   "Elyria", "Hamilton", "Kettering", "Lakewood", "Lorain",
	   "Parma", "Springfield", "Toledo", "Youngstown", "Broken Arrow",
	   "Edmond", "Lawton", "Midwest City", "Moore", "Norman",
	   "Oklahoma City", "Tulsa", "Albany", "Beaverton", "Bend",
	   "Corvallis", "Eugene", "Gresham", "Hillsboro", "Medford",
	   "Portland", "Salem", "Springfield", "Allentown", "Bethlehem",
	   "Erie", "Lancaster", "Philadelphia", "Pittsburgh", "Reading",
	   "Scranton", "Cranston", "Pawtucket", "Providence", "Warwick",
	   "Charleston", "Columbia", "Greenville", "Mount Pleasant", "North Charleston",
	   "Rock Hill", "Rapid City", "Sioux Falls", "Bartlett", "Chattanooga",
	   "Clarksville", "Franklin", "Hendersonville", "Jackson", "Johnson City",
	   "Knoxville", "Memphis", "Murfreesboro", "Nashville-Davidson", "Abilene",
	   "Allen", "Amarillo", "Arlington", "Austin", "Baytown",
	   "Beaumont", "Brownsville", "Bryan", "Carrollton", "Cedar Park",
	   "College Station", "Conroe", "Corpus Christi", "Dallas", "Denton",
	   "DeSoto", "Edinburg", "El Paso", "Euless", "Flower Mound",
	   "Fort Worth", "Frisco", "Garland", "Grand Prairie", "Harlingen",
	   "Houston", "Irving", "Killeen", "Laredo", "League City",
	   "Lewisville", "Longview", "Lubbock", "Mansfield", "McAllen",
	   "McKinney", "Mesquite", "Midland", "Mission", "Missouri City",
	   "New Braunfels", "North Richland Hills", "Odessa", "Pasadena", "Pearland",
	   "Pharr", "Plano", "Port Arthur", "Richardson", "Round Rock",
	   "Rowlett", "San Angelo", "San Antonio", "Sugar Land", "Temple",
	   "Tyler", "Victoria", "Waco", "Wichita Falls", "Layton",
	   "Ogden", "Orem", "Provo", "Salt Lake City", "Sandy",
	   "South Jordan", "St. George", "Taylorsville", "West Jordan", "West Valley City",
	   "Alexandria", "Chesapeake", "Hampton", "Lynchburg", "Newport News",
	   "Norfolk", "Portsmouth", "Richmond", "Roanoke", "Suffolk",
	   "Virginia Beach", "Auburn", "Bellevue", "Bellingham", "Everett",
	   "Federal Way", "Kennewick", "Kent", "Lakewood", "Marysville",
	   "Pasco", "Redmond", "Renton", "Seattle", "Shoreline",
	   "Spokane", "Spokane Valley", "Tacoma", "Vancouver", "Yakima",
	   "Charleston", "Appleton", "Eau Claire", "Green Bay", "Janesville",
	   "Kenosha", "La Crosse", "Madison", "Milwaukee", "Oshkosh",
	   "Racine", "Waukesha", "West Allis", "Casper", "Cheyenne"
	};

	// Other states state names
	std::vector<std::string> OS_state{
	   "Alabama", "Alabama", "Alabama", "Alabama", "Alabama",
	   "Alabama", "Alabama", "Alabama", "Alabama", "Alaska",
	   "Arizona", "Arizona", "Arizona", "Arizona", "Arizona",
	   "Arizona", "Arizona", "Arizona", "Arizona", "Arizona",
	   "Arizona", "Arizona", "Arizona", "Arizona", "Arizona",
	   "Arizona", "Arkansas", "Arkansas", "Arkansas", "Arkansas",
	   "Arkansas", "Arkansas", "Arkansas", "Arkansas", "Colorado",
	   "Colorado", "Colorado", "Colorado", "Colorado", "Colorado",
	   "Colorado", "Colorado", "Colorado", "Colorado", "Colorado",
	   "Colorado", "Colorado", "Colorado", "Colorado", "Colorado",
	   "Connecticut", "Connecticut", "Connecticut", "Connecticut", "Connecticut",
	   "Connecticut", "Connecticut", "Connecticut", "Connecticut", "Connecticut",
	   "Connecticut", "Connecticut", "Delaware", "District of Columbia", "Florida",
	   "Florida", "Florida", "Florida", "Florida", "Florida",
	   "Florida", "Florida", "Florida", "Florida", "Florida",
	   "Florida", "Florida", "Florida", "Florida", "Florida",
	   "Florida", "Florida", "Florida", "Florida", "Florida",
	   "Florida", "Florida", "Florida", "Florida", "Florida",
	   "Florida", "Florida", "Florida", "Florida", "Florida",
	   "Florida", "Florida", "Florida", "Florida", "Florida",
	   "Florida", "Florida", "Florida", "Florida", "Florida",
	   "Florida", "Florida", "Florida", "Florida", "Florida",
	   "Florida", "Florida", "Florida", "Florida", "Florida",
	   "Florida", "Georgia", "Georgia", "Georgia", "Georgia",
	   "Georgia", "Georgia", "Georgia", "Georgia", "Georgia",
	   "Georgia", "Georgia", "Georgia", "Georgia", "Georgia",
	   "Georgia", "Hawaii", "Idaho", "Idaho", "Idaho",
	   "Idaho", "Idaho", "Illinois", "Illinois", "Illinois",
	   "Illinois", "Illinois", "Illinois", "Illinois", "Illinois",
	   "Illinois", "Illinois", "Illinois", "Illinois", "Illinois",
	   "Illinois", "Illinois", "Illinois", "Illinois", "Illinois",
	   "Illinois", "Illinois", "Illinois", "Illinois", "Illinois",
	   "Illinois", "Illinois", "Illinois", "Illinois", "Illinois",
	   "Illinois", "Indiana", "Indiana", "Indiana", "Indiana",
	   "Indiana", "Indiana", "Indiana", "Indiana", "Indiana",
	   "Indiana", "Indiana", "Indiana", "Indiana", "Indiana",
	   "Indiana", "Indiana", "Iowa", "Iowa", "Iowa",
	   "Iowa", "Iowa", "Iowa", "Iowa", "Iowa",
	   "Iowa", "Iowa", "Kansas", "Kansas", "Kansas",
	   "Kansas", "Kansas", "Kansas", "Kansas", "Kansas",
	   "Kentucky", "Kentucky", "Kentucky", "Kentucky", "Louisiana",
	   "Louisiana", "Louisiana", "Louisiana", "Louisiana", "Louisiana",
	   "Louisiana", "Maine", "Maryland", "Maryland", "Maryland",
	   "Maryland", "Maryland", "Massachusetts", "Massachusetts", "Massachusetts",
	   "Massachusetts", "Massachusetts", "Massachusetts", "Massachusetts", "Massachusetts",
	   "Massachusetts", "Massachusetts", "Massachusetts", "Massachusetts", "Massachusetts",
	   "Massachusetts", "Massachusetts", "Massachusetts", "Massachusetts", "Massachusetts",
	   "Massachusetts", "Massachusetts", "Massachusetts", "Massachusetts", "Michigan",
	   "Michigan", "Michigan", "Michigan", "Michigan", "Michigan",
	   "Michigan", "Michigan", "Michigan", "Michigan", "Michigan",
	   "Michigan", "Michigan", "Michigan", "Michigan", "Michigan",
	   "Michigan", "Michigan", "Michigan", "Michigan", "Michigan",
	   "Michigan", "Michigan", "Michigan", "Minnesota", "Minnesota",
	   "Minnesota", "Minnesota", "Minnesota", "Minnesota", "Minnesota",
	   "Minnesota", "Minnesota", "Minnesota", "Minnesota", "Minnesota",
	   "Minnesota", "Minnesota", "Minnesota", "Minnesota", "Minnesota",
	   "Mississippi", "Mississippi", "Missouri", "Missouri", "Missouri",
	   "Missouri", "Missouri", "Missouri", "Missouri", "Missouri",
	   "Missouri", "Missouri", "Missouri", "Missouri", "Missouri",
	   "Montana", "Montana", "Montana", "Nebraska", "Nebraska",
	   "Nebraska", "Nevada", "Nevada", "Nevada", "Nevada",
	   "Nevada", "Nevada", "New Hampshire", "New Hampshire", "New Jersey",
	   "New Jersey", "New Jersey", "New Jersey", "New Jersey", "New Jersey",
	   "New Jersey", "New Jersey", "New Jersey", "New Jersey", "New Jersey",
	   "New Jersey", "New Jersey", "New Jersey", "New Jersey", "New Jersey",
	   "New Jersey", "New Mexico", "New Mexico", "New Mexico", "New Mexico",
	   "New York", "New York", "New York", "New York", "New York",
	   "New York", "New York", "New York", "New York", "New York",
	   "New York", "New York", "New York", "New York", "North Carolina",
	   "North Carolina", "North Carolina", "North Carolina", "North Carolina", "North Carolina",
	   "North Carolina", "North Carolina", "North Carolina", "North Carolina", "North Carolina",
	   "North Carolina", "North Carolina", "North Carolina", "North Carolina", "North Carolina",
	   "North Carolina", "North Dakota", "North Dakota", "North Dakota", "Ohio",
	   "Ohio", "Ohio", "Ohio", "Ohio", "Ohio",
	   "Ohio", "Ohio", "Ohio", "Ohio", "Ohio",
	   "Ohio", "Ohio", "Ohio", "Ohio", "Oklahoma",
	   "Oklahoma", "Oklahoma", "Oklahoma", "Oklahoma", "Oklahoma",
	   "Oklahoma", "Oklahoma", "Oregon", "Oregon", "Oregon",
	   "Oregon", "Oregon", "Oregon", "Oregon", "Oregon",
	   "Oregon", "Oregon", "Oregon", "Pennsylvania", "Pennsylvania",
	   "Pennsylvania", "Pennsylvania", "Pennsylvania", "Pennsylvania", "Pennsylvania",
	   "Pennsylvania", "Rhode Island", "Rhode Island", "Rhode Island", "Rhode Island",
	   "South Carolina", "South Carolina", "South Carolina", "South Carolina", "South Carolina",
	   "South Carolina", "South Dakota", "South Dakota", "Tennessee", "Tennessee",
	   "Tennessee", "Tennessee", "Tennessee", "Tennessee", "Tennessee",
	   "Tennessee", "Tennessee", "Tennessee", "Tennessee", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Texas",
	   "Texas", "Texas", "Texas", "Texas", "Utah",
	   "Utah", "Utah", "Utah", "Utah", "Utah",
	   "Utah", "Utah", "Utah", "Utah", "Utah",
	   "Virginia", "Virginia", "Virginia", "Virginia", "Virginia",
	   "Virginia", "Virginia", "Virginia", "Virginia", "Virginia",
	   "Virginia", "Washington", "Washington", "Washington", "Washington",
	   "Washington", "Washington", "Washington", "Washington", "Washington",
	   "Washington", "Washington", "Washington", "Washington", "Washington",
	   "Washington", "Washington", "Washington", "Washington", "Washington",
	   "West Virginia", "Wisconsin", "Wisconsin", "Wisconsin", "Wisconsin",
	   "Wisconsin", "Wisconsin", "Wisconsin", "Wisconsin", "Wisconsin",
	   "Wisconsin", "Wisconsin", "Wisconsin", "Wyoming", "Wyoming"
	};

	QHeap<CensusCity>* q;
	CensusCity* temp, * result;

	// set up quartile heap to use 2010 census data
	q = new QHeap<CensusCity>(2000);

	std::cout << std::endl << std::endl << "==== Using 2010 Census Data  ===" << std::endl;

	// Insert stats for cities in California

	for (size_t i = 0; i < CA_2010.size(); i++)
	{
		temp = new CensusCity(CA_city[i], CA_state[i], CA_2010[i], CA_2011[i], false);
		q->insert(temp);
	}


	std::cout << std::endl << "*** Report on cities in California with population >50,000" << std::endl;
	result = q->getMin();
	std::cout << "   The smallest city in California is: " + result->toString() << std::endl;
	result = q->get25();
	std::cout << "   The 25th percentile city in California is: " + result->toString() << std::endl;
	result = q->get50();
	std::cout << "   The median city in California is: " + result->toString() << std::endl;
	result = q->get75();
	std::cout << "   The 75th percentile city in California is: " + result->toString() << std::endl;
	result = q->getMax();
	std::cout << "   The largest city in California is: " + result->toString() << std::endl;

	//q->dump(); //was -----//commented

	// Insert stats for other states in the US

	for (size_t i = 0; i < OS_2010.size(); i++)
	{
		temp = new CensusCity(OS_city[i], OS_state[i], OS_2010[i], OS_2011[i], false);
		q->insert(temp);
	}

	std::cout << std::endl << "*** Report on cities in the U.S. with population >50,000" << std::endl;
	result = q->getMin();
	std::cout << "   The smallest city in the U.S. is: " + result->toString() << std::endl;
	result = q->get25();
	std::cout << "   The 25th percentile city in the U.S. is: " + result->toString() << std::endl;
	result = q->get50();
	std::cout << "   The median city in the U.S. is: " + result->toString() << std::endl;
	result = q->get75();
	std::cout << "   The 75th percentile city in the U.S. is: " + result->toString() << std::endl;
	result = q->getMax();
	std::cout << "   The largest city in California is: " + result->toString() << std::endl;

	//q->dump() ;

	delete q;

	// set up quartile heap to use 2011 estimated population 
	QHeap<CensusCity>* q2 = new QHeap<CensusCity>(2000);

	std::cout << std::endl << std::endl << "==== Using 2011 Estimated Population ===" << std::endl;

	// Insert stats for cities in California

	for (size_t i = 0; i < CA_2010.size(); i++) {

		temp = new CensusCity(CA_city[i], CA_state[i], CA_2010[i], CA_2011[i], true);
		q2->insert(temp);
	}


	std::cout << std::endl << "*** Report on cities in California with population >50,000" << std::endl;
	result = q2->getMin();
	std::cout << "   The smallest city in California is: " + result->toString() << std::endl;
	result = q2->get25();
	std::cout << "   The 25th percentile city in California is: " + result->toString() << std::endl;
	result = q2->get50();
	std::cout << "   The median city in California is: " + result->toString() << std::endl;
	result = q2->get75();
	std::cout << "   The 75th percentile city in California is: " + result->toString() << std::endl;
	result = q2->getMax();
	std::cout << "   The largest city in California is: " + result->toString() << std::endl;

	//q2->dump() ;

	// Insert stats for other states in the US

	for (size_t i = 0; i < OS_2010.size(); i++) {

		temp = new CensusCity(OS_city[i], OS_state[i], OS_2010[i], OS_2011[i], true);
		q2->insert(temp);
	}

	std::cout << std::endl << "*** Report on cities in the U.S. with population >50,000" << std::endl;
	result = q2->getMin();
	std::cout << "   The smallest city in the U.S. is: " + result->toString() << std::endl;
	result = q2->get25();
	std::cout << "   The 25th percentile city in the U.S. is: " + result->toString() << std::endl;
	result = q2->get50();
	std::cout << "   The median city in the U.S. is: " + result->toString() << std::endl;
	result = q2->get75();
	std::cout << "   The 75th percentile city in the U.S. is: " + result->toString() << std::endl;
	result = q2->getMax();
	std::cout << "   The largest city in California is: " + result->toString() << std::endl;

	//q2->dump() ;

	delete q2;
}

int main()
{
	//bool test = true;
	//int t;
	//What is this?

	test1();
	test2();
	test3();

	/*
	#ifdef _WIN32
	_CrtDumpMemoryLeaks();
	#endif // _WIN32
	*/

	return 0;
}