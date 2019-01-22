#include "my_seamless_cloning.hpp"

using namespace std;

namespace homme {
	static cv::Mat checkMask(cv::InputArray _mask, cv::Size size);
	void seamlessClone(cv::InputArray _src, cv::InputArray _dst, cv::InputArray _mask, cv::Point p, cv::OutputArray _blend, int flags);
}

static cv::Mat homme::checkMask(cv::InputArray _mask, cv::Size size) {
	cv::Mat mask = _mask.getMat();
	cv::Mat gray;
	if (mask.channels() == 3)
		cv::cvtColor(mask, gray, cv::COLOR_BGR2GRAY);
	else
	{
		if (mask.empty())
			gray = cv::Mat(size.height, size.width, CV_8UC1, cv::Scalar(255));
		else
			mask.copyTo(gray);
	}

	return gray;
}

void homme::seamlessClone(cv::InputArray _src, cv::InputArray _dst, cv::InputArray _mask, cv::Point p, cv::OutputArray _blend, int flags){
	const cv::Mat src = _src.getMat();
	const cv::Mat dest = _dst.getMat();
	cv::Mat mask = checkMask(_mask, src.size());
}
