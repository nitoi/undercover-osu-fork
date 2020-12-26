
class Config {
public:
	struct Relax {
		static inline bool isEnabled;
		static inline bool manualSpinners;
		static inline bool waitLate;
		static inline int tappingStyle;
		static inline int maxBpm = 10;
		static inline int singleTapBpm = 10;
		static inline int alternationBpm = 10;
	};
	struct Timewarp {
		static inline bool isEnabled;
		static inline float multiplier;
	};
	struct AimAssist {
		static inline bool isEnabled;
		static inline float fov;
	};
	struct Visuals {
		static inline bool isEnabled;
		static inline bool flashlight;
		static inline bool hidden;
	};
	struct Misc {

	};
};