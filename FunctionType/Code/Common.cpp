#include "stdafx.h"
#include "Common.hpp"
#include "EnumClassOperator.hpp"

namespace WinSvcLib {
	ServiceAccessType operator | (const ServiceAccessType A, const ServiceAccessType B) {
		return Operator(A, B);
	}

	ServiceType operator | (const ServiceType A, const ServiceType B) {
		return Operator(A, B);
	}
}
