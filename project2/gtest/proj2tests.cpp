#include <vector>
#include <gtest/gtest.h>
#include "proj2.hpp"
#include "ver.hpp"

namespace{

TEST(SampleTests, MSTn10)
	{
		std::vector< std::vector< unsigned>  > gr = { 
			{ 0, 12, 12, 13, 17, 9, 7, 14, 3, 17},
			{ 12, 0, 8, 8, 8, 18, 19, 5, 15, 8},
			{ 12, 8, 0, 12, 15, 19, 17, 12, 9, 8},
			{ 13, 8, 12, 0, 6, 15, 14, 3, 10, 4},
			{ 17, 8, 15, 6, 0, 21, 19, 3, 14, 10},
			{ 9, 18, 19, 15, 21, 0, 11, 18, 10, 11},
			{ 7, 19, 17, 14, 19, 11, 0, 17, 10, 18},
			{ 14, 5, 12, 3, 3, 18, 17, 0, 11, 7},
			{ 3, 15, 9, 10, 14, 10, 10, 11, 0, 14},
			{ 17, 8, 8, 4, 10, 11, 18, 7, 14, 0}
		};

		std::vector<Edge> mst = compute_mst(gr);
		EXPECT_TRUE( verifyMST(mst, gr) );
	}

    
	TEST(SampleTests, MSTn20)
	{
		std::vector< std::vector< unsigned>  > gr = { 
			{ 0, 8, 14, 10, 9, 8, 7, 6, 3, 12, 6, 10, 11, 9, 13, 5, 8, 8, 9, 13},
			{ 8, 0, 12, 11, 6, 6, 8, 9, 6, 11, 3, 10, 4, 12, 11, 3, 11, 7, 7, 12},
			{ 14, 12, 0, 10, 11, 16, 12, 13, 11, 9, 14, 16, 8, 12, 9, 15, 15, 11, 10, 5},
			{ 10, 11, 10, 0, 6, 14, 3, 13, 11, 10, 9, 9, 13, 16, 11, 11, 6, 10, 10, 10},
			{ 9, 6, 11, 6, 0, 11, 9, 7, 6, 12, 3, 12, 10, 10, 8, 9, 11, 8, 4, 12},
			{ 8, 6, 16, 14, 11, 0, 11, 11, 11, 13, 8, 8, 8, 14, 9, 3, 15, 11, 8, 11},
			{ 7, 8, 12, 3, 9, 11, 0, 13, 10, 11, 11, 6, 10, 14, 8, 8, 9, 7, 11, 7},
			{ 6, 9, 13, 13, 7, 11, 13, 0, 3, 11, 6, 15, 10, 3, 7, 11, 8, 7, 3, 10},
			{ 3, 6, 11, 11, 6, 11, 10, 3, 0, 14, 3, 12, 10, 6, 10, 8, 5, 10, 6, 10},
			{ 12, 11, 9, 10, 12, 13, 11, 11, 14, 0, 12, 10, 7, 14, 12, 14, 14, 4, 8, 7},
			{ 6, 3, 14, 9, 3, 8, 11, 6, 3, 12, 0, 12, 7, 9, 8, 6, 8, 8, 4, 9},
			{ 10, 10, 16, 9, 12, 8, 6, 15, 12, 10, 12, 0, 14, 18, 12, 11, 15, 13, 16, 13},
			{ 11, 4, 8, 13, 10, 8, 10, 10, 10, 7, 7, 14, 0, 13, 11, 7, 7, 3, 7, 13},
			{ 9, 12, 12, 16, 10, 14, 14, 3, 6, 14, 9, 18, 13, 0, 10, 14, 11, 10, 6, 7},
			{ 13, 11, 9, 11, 8, 9, 8, 7, 10, 12, 8, 12, 11, 10, 0, 12, 7, 8, 4, 14},
			{ 5, 3, 15, 11, 9, 3, 8, 11, 8, 14, 6, 11, 7, 14, 12, 0, 13, 10, 10, 14},
			{ 8, 11, 15, 6, 11, 15, 9, 8, 5, 14, 8, 15, 7, 11, 7, 13, 0, 10, 11, 15},
			{ 8, 7, 11, 10, 8, 11, 7, 7, 10, 4, 8, 13, 3, 10, 8, 10, 10, 0, 4, 11},
			{ 9, 7, 10, 10, 4, 8, 11, 3, 6, 8, 4, 16, 7, 6, 4, 10, 11, 4, 0, 13},
			{ 13, 12, 5, 10, 12, 11, 7, 10, 10, 7, 9, 13, 13, 7, 14, 14, 15, 11, 13, 0}
		};

		std::vector<Edge> mst = compute_mst(gr);
		EXPECT_TRUE( verifyMST(mst, gr) );
	}


	TEST(SampleTests, TSPJourney_n10)
	{
		std::vector< std::vector< unsigned>  > gr = { 
			{ 0, 12, 12, 13, 17, 9, 7, 14, 3, 17},
			{ 12, 0, 8, 8, 8, 18, 19, 5, 15, 8},
			{ 12, 8, 0, 12, 15, 19, 17, 12, 9, 8},
			{ 13, 8, 12, 0, 6, 15, 14, 3, 10, 4},
			{ 17, 8, 15, 6, 0, 21, 19, 3, 14, 10},
			{ 9, 18, 19, 15, 21, 0, 11, 18, 10, 11},
			{ 7, 19, 17, 14, 19, 11, 0, 17, 10, 18},
			{ 14, 5, 12, 3, 3, 18, 17, 0, 11, 7},
			{ 3, 15, 9, 10, 14, 10, 10, 11, 0, 14},
			{ 17, 8, 8, 4, 10, 11, 18, 7, 14, 0}
		};

		unsigned start = 0;
		unsigned n = 10;
		std::vector<Edge> mst = compute_mst(gr);
		std::vector<unsigned> journey = computeTSPJourney(mst, start); 
		EXPECT_TRUE( verifyMST(mst, gr) );
		EXPECT_TRUE( verifyTSPJourney(n, journey, mst, start) ); 
	}


	TEST(SampleTests, TSPJourney_n20)
	{
		std::vector< std::vector< unsigned>  > gr = { 
			{ 0, 8, 14, 10, 9, 8, 7, 6, 3, 12, 6, 10, 11, 9, 13, 5, 8, 8, 9, 13},
			{ 8, 0, 12, 11, 6, 6, 8, 9, 6, 11, 3, 10, 4, 12, 11, 3, 11, 7, 7, 12},
			{ 14, 12, 0, 10, 11, 16, 12, 13, 11, 9, 14, 16, 8, 12, 9, 15, 15, 11, 10, 5},
			{ 10, 11, 10, 0, 6, 14, 3, 13, 11, 10, 9, 9, 13, 16, 11, 11, 6, 10, 10, 10},
			{ 9, 6, 11, 6, 0, 11, 9, 7, 6, 12, 3, 12, 10, 10, 8, 9, 11, 8, 4, 12},
			{ 8, 6, 16, 14, 11, 0, 11, 11, 11, 13, 8, 8, 8, 14, 9, 3, 15, 11, 8, 11},
			{ 7, 8, 12, 3, 9, 11, 0, 13, 10, 11, 11, 6, 10, 14, 8, 8, 9, 7, 11, 7},
			{ 6, 9, 13, 13, 7, 11, 13, 0, 3, 11, 6, 15, 10, 3, 7, 11, 8, 7, 3, 10},
			{ 3, 6, 11, 11, 6, 11, 10, 3, 0, 14, 3, 12, 10, 6, 10, 8, 5, 10, 6, 10},
			{ 12, 11, 9, 10, 12, 13, 11, 11, 14, 0, 12, 10, 7, 14, 12, 14, 14, 4, 8, 7},
			{ 6, 3, 14, 9, 3, 8, 11, 6, 3, 12, 0, 12, 7, 9, 8, 6, 8, 8, 4, 9},
			{ 10, 10, 16, 9, 12, 8, 6, 15, 12, 10, 12, 0, 14, 18, 12, 11, 15, 13, 16, 13},
			{ 11, 4, 8, 13, 10, 8, 10, 10, 10, 7, 7, 14, 0, 13, 11, 7, 7, 3, 7, 13},
			{ 9, 12, 12, 16, 10, 14, 14, 3, 6, 14, 9, 18, 13, 0, 10, 14, 11, 10, 6, 7},
			{ 13, 11, 9, 11, 8, 9, 8, 7, 10, 12, 8, 12, 11, 10, 0, 12, 7, 8, 4, 14},
			{ 5, 3, 15, 11, 9, 3, 8, 11, 8, 14, 6, 11, 7, 14, 12, 0, 13, 10, 10, 14},
			{ 8, 11, 15, 6, 11, 15, 9, 8, 5, 14, 8, 15, 7, 11, 7, 13, 0, 10, 11, 15},
			{ 8, 7, 11, 10, 8, 11, 7, 7, 10, 4, 8, 13, 3, 10, 8, 10, 10, 0, 4, 11},
			{ 9, 7, 10, 10, 4, 8, 11, 3, 6, 8, 4, 16, 7, 6, 4, 10, 11, 4, 0, 13},
			{ 13, 12, 5, 10, 12, 11, 7, 10, 10, 7, 9, 13, 13, 7, 14, 14, 15, 11, 13, 0}
		};

		unsigned start = 0;
		unsigned n = 20;
		std::vector<Edge> mst = compute_mst(gr);
		std::vector<unsigned> journey = computeTSPJourney(mst, start); 
		EXPECT_TRUE( verifyMST(mst, gr) );
		EXPECT_TRUE( verifyTSPJourney(n, journey, mst, start) );
	}

	TEST(SampleTests, MeasureWaste_n30)
	{
		std::vector< std::vector< unsigned>  > gr = { 
			{ 0, 289, 168, 189, 111, 118, 84, 111, 43, 43, 60, 183, 250, 68, 13, 149, 162, 196, 236, 172, 139, 87, 231, 228, 147, 100, 214, 61, 204, 146},
			{ 289, 0, 294, 185, 280, 300, 253, 226, 246, 257, 229, 285, 153, 330, 287, 180, 217, 266, 93, 202, 207, 301, 143, 401, 321, 246, 264, 264, 319, 200},
			{ 168, 294, 0, 154, 260, 200, 237, 264, 196, 125, 213, 218, 215, 188, 155, 114, 77, 28, 201, 137, 140, 81, 196, 163, 227, 139, 46, 188, 101, 133},
			{ 189, 185, 154, 0, 106, 216, 133, 160, 162, 206, 179, 151, 61, 229, 176, 40, 77, 126, 92, 17, 68, 235, 42, 261, 187, 105, 200, 179, 255, 66},
			{ 111, 280, 260, 106, 0, 156, 27, 54, 68, 149, 85, 221, 167, 179, 124, 146, 183, 232, 187, 123, 164, 193, 148, 334, 185, 125, 284, 86, 229, 171},
			{ 118, 300, 200, 216, 156, 0, 129, 156, 88, 75, 71, 65, 272, 160, 105, 222, 207, 228, 212, 199, 157, 119, 258, 212, 29, 145, 246, 106, 215, 150},
			{ 84, 253, 237, 133, 27, 129, 0, 27, 41, 122, 58, 194, 194, 152, 97, 173, 160, 209, 160, 150, 137, 166, 175, 307, 158, 98, 257, 59, 202, 144},
			{ 111, 226, 264, 160, 54, 156, 27, 0, 68, 149, 85, 221, 193, 179, 124, 200, 187, 236, 133, 177, 164, 193, 183, 308, 185, 125, 284, 86, 229, 171},
			{ 43, 246, 196, 162, 68, 88, 41, 68, 0, 81, 17, 153, 223, 111, 56, 156, 119, 168, 201, 145, 96, 125, 204, 266, 117, 57, 216, 18, 161, 103},
			{ 43, 257, 125, 206, 149, 75, 122, 149, 81, 0, 98, 140, 238, 85, 30, 166, 200, 153, 253, 189, 177, 44, 248, 185, 104, 138, 171, 63, 226, 184},
			{ 60, 229, 213, 179, 85, 71, 58, 85, 17, 98, 0, 136, 240, 128, 73, 173, 136, 185, 218, 162, 113, 142, 221, 283, 100, 74, 199, 35, 144, 120},
			{ 183, 285, 218, 151, 221, 65, 194, 221, 153, 140, 136, 0, 212, 225, 170, 157, 193, 190, 192, 134, 92, 182, 193, 242, 36, 131, 264, 171, 280, 85},
			{ 250, 153, 215, 61, 167, 272, 194, 193, 223, 238, 240, 212, 0, 206, 237, 101, 138, 187, 60, 78, 129, 194, 19, 322, 248, 166, 261, 206, 283, 127},
			{ 68, 330, 188, 229, 179, 160, 152, 179, 111, 85, 128, 225, 206, 0, 55, 191, 228, 216, 237, 214, 203, 129, 187, 270, 189, 168, 234, 129, 247, 210},
			{ 13, 287, 155, 176, 124, 105, 97, 124, 56, 30, 73, 170, 237, 55, 0, 136, 173, 183, 223, 159, 148, 74, 218, 215, 134, 113, 201, 74, 217, 155},
			{ 149, 180, 114, 40, 146, 222, 173, 200, 156, 166, 173, 157, 101, 191, 136, 0, 37, 86, 87, 23, 79, 195, 82, 221, 193, 99, 160, 174, 215, 72},
			{ 162, 217, 77, 77, 183, 207, 160, 187, 119, 200, 136, 193, 138, 228, 173, 37, 0, 49, 124, 60, 101, 158, 119, 184, 229, 62, 123, 137, 178, 108},
			{ 196, 266, 28, 126, 232, 228, 209, 236, 168, 153, 185, 190, 187, 216, 183, 86, 49, 0, 173, 109, 112, 109, 168, 135, 226, 111, 74, 186, 129, 105},
			{ 236, 93, 201, 92, 187, 212, 160, 133, 201, 253, 218, 192, 60, 237, 223, 87, 124, 173, 0, 109, 114, 254, 50, 308, 228, 153, 242, 219, 297, 107},
			{ 172, 202, 137, 17, 123, 199, 150, 177, 145, 189, 162, 134, 78, 214, 159, 23, 60, 109, 109, 0, 56, 218, 59, 244, 170, 88, 183, 162, 238, 49},
			{ 139, 207, 140, 68, 164, 157, 137, 164, 96, 177, 113, 92, 129, 203, 148, 79, 101, 112, 114, 56, 0, 221, 110, 247, 128, 39, 186, 114, 241, 7},
			{ 87, 301, 81, 235, 193, 119, 166, 193, 125, 44, 142, 182, 194, 129, 74, 195, 158, 109, 254, 218, 221, 0, 213, 141, 146, 182, 127, 107, 182, 214},
			{ 231, 143, 196, 42, 148, 258, 175, 183, 204, 248, 221, 193, 19, 187, 218, 82, 119, 168, 50, 59, 110, 213, 0, 303, 229, 147, 242, 221, 297, 108},
			{ 228, 401, 163, 261, 334, 212, 307, 308, 266, 185, 283, 242, 322, 270, 215, 221, 184, 135, 308, 244, 247, 141, 303, 0, 241, 212, 209, 248, 264, 240},
			{ 147, 321, 227, 187, 185, 29, 158, 185, 117, 104, 100, 36, 248, 189, 134, 193, 229, 226, 228, 170, 128, 146, 229, 241, 0, 167, 273, 135, 244, 121},
			{ 100, 246, 139, 105, 125, 145, 98, 125, 57, 138, 74, 131, 166, 168, 113, 99, 62, 111, 153, 88, 39, 182, 147, 212, 167, 0, 163, 75, 218, 46},
			{ 214, 264, 46, 200, 284, 246, 257, 284, 216, 171, 199, 264, 261, 234, 201, 160, 123, 74, 242, 183, 186, 127, 242, 209, 273, 163, 0, 234, 55, 179},
			{ 61, 264, 188, 179, 86, 106, 59, 86, 18, 63, 35, 171, 206, 129, 74, 174, 137, 186, 219, 162, 114, 107, 221, 248, 135, 75, 234, 0, 179, 121},
			{ 204, 319, 101, 255, 229, 215, 202, 229, 161, 226, 144, 280, 283, 247, 217, 215, 178, 129, 297, 238, 241, 182, 297, 264, 244, 218, 55, 179, 0, 234},
			{ 146, 200, 133, 66, 171, 150, 144, 171, 103, 184, 120, 85, 127, 210, 155, 72, 108, 105, 107, 49, 7, 214, 108, 240, 121, 46, 179, 121, 234, 0}
		};

		unsigned start = 0;
		unsigned n = 30;
		std::vector<Edge> mst = compute_mst(gr);
		std::vector<unsigned> journey = computeTSPJourney(mst, start); 
		unsigned wa = waste(mst, journey, gr); 
		EXPECT_TRUE( verifyMST(mst, gr) );
		EXPECT_TRUE( verifyTSPJourney(n, journey, mst, start) );
		EXPECT_TRUE( verifyWaste(mst, journey, gr, wa) );
	}

}
