// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// IApplicationGE wrapper class

class IApplicationGE : public COleDispatchDriver
{
public:
	IApplicationGE() {}		// Calls COleDispatchDriver default constructor
	IApplicationGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IApplicationGE(const IApplicationGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetCamera(long considerTerrain);
	void SetCamera(LPDISPATCH camera, double speed);
	void SetCameraParams(double lat, double lon, double alt, long altMode, double Range, double Tilt, double Azimuth, double speed);
	long GetStreamingProgressPercentage();
	void SaveScreenShot(LPCTSTR fileName, long quality);
	void OpenKmlFile(LPCTSTR fileName, long suppressMessages);
	void LoadKmlData(BSTR* kmlData);
	double GetAutoPilotSpeed();
	void SetAutoPilotSpeed(double newValue);
	LPDISPATCH GetViewExtents();
	LPDISPATCH GetFeatureByName(LPCTSTR Name);
	LPDISPATCH GetFeatureByHref(LPCTSTR href);
	void SetFeatureView(LPDISPATCH feature, double speed);
	LPDISPATCH GetPointOnTerrainFromScreenCoords(double screen_x, double screen_y);
	long GetVersionMajor();
	long GetVersionMinor();
	long GetVersionBuild();
	long GetVersionAppType();
	long IsInitialized();
	long IsOnline();
	void Login();
	void Logout();
	void ShowDescriptionBalloon(LPDISPATCH feature);
	void HideDescriptionBalloons();
	LPDISPATCH GetHighlightedFeature();
	LPDISPATCH GetMyPlaces();
	LPDISPATCH GetTemporaryPlaces();
	LPDISPATCH GetLayersDatabases();
	double GetElevationExaggeration();
	void SetElevationExaggeration(double newValue);
	long GetMainHwnd();
	LPDISPATCH GetTourController();
	LPDISPATCH GetSearchController();
	LPDISPATCH GetAnimationController();
	long GetRenderHwnd();
};
/////////////////////////////////////////////////////////////////////////////
// ICameraInfoGE wrapper class

class ICameraInfoGE : public COleDispatchDriver
{
public:
	ICameraInfoGE() {}		// Calls COleDispatchDriver default constructor
	ICameraInfoGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ICameraInfoGE(const ICameraInfoGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	double GetFocusPointLatitude();
	void SetFocusPointLatitude(double newValue);
	double GetFocusPointLongitude();
	void SetFocusPointLongitude(double newValue);
	double GetFocusPointAltitude();
	void SetFocusPointAltitude(double newValue);
	long GetFocusPointAltitudeMode();
	void SetFocusPointAltitudeMode(long nNewValue);
	double GetRange();
	void SetRange(double newValue);
	double GetTilt();
	void SetTilt(double newValue);
	double GetAzimuth();
	void SetAzimuth(double newValue);
};
/////////////////////////////////////////////////////////////////////////////
// IViewExtentsGE wrapper class

class IViewExtentsGE : public COleDispatchDriver
{
public:
	IViewExtentsGE() {}		// Calls COleDispatchDriver default constructor
	IViewExtentsGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IViewExtentsGE(const IViewExtentsGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	double GetNorth();
	double GetSouth();
	double GetEast();
	double GetWest();
};
/////////////////////////////////////////////////////////////////////////////
// IFeatureGE wrapper class

class IFeatureGE : public COleDispatchDriver
{
public:
	IFeatureGE() {}		// Calls COleDispatchDriver default constructor
	IFeatureGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IFeatureGE(const IFeatureGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	CString GetName();
	long GetVisibility();
	void SetVisibility(long nNewValue);
	long GetHasView();
	long GetHighlighted();
	void Highlight();
	LPDISPATCH GetParent();
	LPDISPATCH GetChildren();
	LPDISPATCH GetTimeInterval();
};
/////////////////////////////////////////////////////////////////////////////
// IFeatureCollectionGE wrapper class

class IFeatureCollectionGE : public COleDispatchDriver
{
public:
	IFeatureCollectionGE() {}		// Calls COleDispatchDriver default constructor
	IFeatureCollectionGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IFeatureCollectionGE(const IFeatureCollectionGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPUNKNOWN Get_NewEnum();
	LPDISPATCH GetItem(long index);
	long GetCount();
};
/////////////////////////////////////////////////////////////////////////////
// ITimeIntervalGE wrapper class

class ITimeIntervalGE : public COleDispatchDriver
{
public:
	ITimeIntervalGE() {}		// Calls COleDispatchDriver default constructor
	ITimeIntervalGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ITimeIntervalGE(const ITimeIntervalGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH GetBeginTime();
	LPDISPATCH GetEndTime();
};
/////////////////////////////////////////////////////////////////////////////
// ITimeGE wrapper class

class ITimeGE : public COleDispatchDriver
{
public:
	ITimeGE() {}		// Calls COleDispatchDriver default constructor
	ITimeGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ITimeGE(const ITimeGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetType();
	void SetType(long nNewValue);
	long GetYear();
	void SetYear(long nNewValue);
	long GetMonth();
	void SetMonth(long nNewValue);
	long GetDay();
	void SetDay(long nNewValue);
	long GetHour();
	void SetHour(long nNewValue);
	long GetMinute();
	void SetMinute(long nNewValue);
	long GetSecond();
	void SetSecond(long nNewValue);
	double GetTimeZone();
	void SetTimeZone(double newValue);
	LPDISPATCH Clone();
	LPDISPATCH ConvertToZone(double TimeZone);
};
/////////////////////////////////////////////////////////////////////////////
// IPointOnTerrainGE wrapper class

class IPointOnTerrainGE : public COleDispatchDriver
{
public:
	IPointOnTerrainGE() {}		// Calls COleDispatchDriver default constructor
	IPointOnTerrainGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IPointOnTerrainGE(const IPointOnTerrainGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	double GetLatitude();
	double GetLongitude();
	double GetAltitude();
	long GetProjectedOntoGlobe();
	long GetZeroElevationExaggeration();
};
/////////////////////////////////////////////////////////////////////////////
// ITourControllerGE wrapper class

class ITourControllerGE : public COleDispatchDriver
{
public:
	ITourControllerGE() {}		// Calls COleDispatchDriver default constructor
	ITourControllerGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ITourControllerGE(const ITourControllerGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void PlayOrPause();
	void Stop();
	double GetSpeed();
	void SetSpeed(double newValue);
	double GetPauseDelay();
	void SetPauseDelay(double newValue);
	long GetCycles();
	void SetCycles(long nNewValue);
};
/////////////////////////////////////////////////////////////////////////////
// ISearchControllerGE wrapper class

class ISearchControllerGE : public COleDispatchDriver
{
public:
	ISearchControllerGE() {}		// Calls COleDispatchDriver default constructor
	ISearchControllerGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	ISearchControllerGE(const ISearchControllerGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void Search(LPCTSTR searchString);
	long IsSearchInProgress();
	LPDISPATCH GetResults();
	void ClearResults();
};
/////////////////////////////////////////////////////////////////////////////
// IAnimationControllerGE wrapper class

class IAnimationControllerGE : public COleDispatchDriver
{
public:
	IAnimationControllerGE() {}		// Calls COleDispatchDriver default constructor
	IAnimationControllerGE(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IAnimationControllerGE(const IAnimationControllerGE& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void Play();
	void Pause();
	LPDISPATCH GetSliderTimeInterval();
	LPDISPATCH GetCurrentTimeInterval();
	void SetCurrentTimeInterval(LPDISPATCH newValue);
};
/////////////////////////////////////////////////////////////////////////////
// IKHInterface wrapper class

class IKHInterface : public COleDispatchDriver
{
public:
	IKHInterface() {}		// Calls COleDispatchDriver default constructor
	IKHInterface(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IKHInterface(const IKHInterface& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	LPDISPATCH currentView(long terrain);
	long GetStreamingProgressPercentage();
	void SaveScreenShot(LPCTSTR fileName, long quality);
	void OpenFile(LPCTSTR fileName);
	void QuitApplication();
	void SetRenderWindowSize(long width, long height);
	double GetAutoPilotSpeed();
	void SetAutoPilotSpeed(double newValue);
	LPDISPATCH GetCurrentViewExtents();
	void setView(LPDISPATCH view, long terrain, double speed);
	void LoadKml(BSTR* kmlData);
	LPDISPATCH GetFeatureByName(LPCTSTR Name);
	void setViewParams(double lat, double lon, double Range, double Tilt, double Azimuth, long terrain, double speed);
	void SetFeatureView(LPDISPATCH feature, double speed);
	// method 'GetPointOnTerrainFromScreenCoords' not emitted because of invalid return type or parameter type
	void getCurrentVersion(long* major, long* minor, long* build, long* appType);
	void isClientInitialized(long* IsInitialized);
};
/////////////////////////////////////////////////////////////////////////////
// IKHViewInfo wrapper class

class IKHViewInfo : public COleDispatchDriver
{
public:
	IKHViewInfo() {}		// Calls COleDispatchDriver default constructor
	IKHViewInfo(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IKHViewInfo(const IKHViewInfo& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	double GetLatitude();
	void SetLatitude(double newValue);
	double GetLongitude();
	void SetLongitude(double newValue);
	double GetRange();
	void SetRange(double newValue);
	double GetTilt();
	void SetTilt(double newValue);
	double GetAzimuth();
	void SetAzimuth(double newValue);
};
/////////////////////////////////////////////////////////////////////////////
// IKHViewExtents wrapper class

class IKHViewExtents : public COleDispatchDriver
{
public:
	IKHViewExtents() {}		// Calls COleDispatchDriver default constructor
	IKHViewExtents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IKHViewExtents(const IKHViewExtents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	double GetNorth();
	double GetSouth();
	double GetEast();
	double GetWest();
};
/////////////////////////////////////////////////////////////////////////////
// IKHFeature wrapper class

class IKHFeature : public COleDispatchDriver
{
public:
	IKHFeature() {}		// Calls COleDispatchDriver default constructor
	IKHFeature(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	IKHFeature(const IKHFeature& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetVisibility();
	void SetVisibility(long nNewValue);
	long GetHasView();
};
