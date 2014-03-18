/* Autogenerated with Kurento Idl */

#include <memory>

#include "MediaPipeline.hpp"
#include "WindowParam.hpp"
#include "PointerDetectorWindowMediaParam.hpp"
#include "PointerDetectorAdvFilter.hpp"
#include <JsonSerializer.hpp>

namespace kurento {

MediaObject * PointerDetectorAdvFilter::Factory::createObjectPointer (const Json::Value &params)
{
  std::shared_ptr<MediaPipeline> mediaPipeline;
  std::shared_ptr<WindowParam> calibrationRegion;
  std::vector<std::shared_ptr<PointerDetectorWindowMediaParam>> windows;
  int garbagePeriod = 0;

  if (!params.isMember ("mediaPipeline")) {
    /* param 'mediaPipeline' not present, raise exception */
    JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                              "'mediaPipeline' parameter is requiered");
    throw e;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(mediaPipeline);
  }

  if (!params.isMember ("calibrationRegion")) {
    /* param 'calibrationRegion' not present, raise exception */
    JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                              "'calibrationRegion' parameter is requiered");
    throw e;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(calibrationRegion);
  }

  if (!params.isMember ("windows")) {
    // Warning, optional constructor parameter 'windows' but no default value provided
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(windows);
  }

  if (!params.isMember ("garbagePeriod")) {
    /* param 'garbagePeriod' not present, using default */
    garbagePeriod = 120;
  } else {
    JsonSerializer s(false);
    s.JsonValue = params;
    s.SerializeNVP(garbagePeriod);
  }

  return createObject (mediaPipeline, calibrationRegion, windows, garbagePeriod);
}

PointerDetectorAdvFilter::Factory::StaticConstructor PointerDetectorAdvFilter::Factory::staticConstructor;

PointerDetectorAdvFilter::Factory::StaticConstructor::StaticConstructor()
{
  if (objectRegistrar) {
    std::shared_ptr <Factory> factory (new PointerDetectorAdvFilter::Factory());

    objectRegistrar->registerFactory(factory);
  }
}

void
PointerDetectorAdvFilter::Invoker::invoke (std::shared_ptr<MediaObject> obj,
    const std::string &methodName, const Json::Value &params,
    Json::Value &response)
{
  if (methodName == "addWindow" && params.size() == 1) {
    Json::Value aux;
    std::shared_ptr<PointerDetectorWindowMediaParam> window;

    if (!params.isMember ("window")) {
      /* param 'window' not present, raise exception */
      JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'window' parameter is requiered");
      throw e;
    } else {
      aux = params["window"];

      if (!aux.isObject ()) {
        /* param 'window' has invalid type value, raise exception */
        JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'window' parameter should be a object");
        throw e;
      }

      window = std::shared_ptr<PointerDetectorWindowMediaParam> (new PointerDetectorWindowMediaParam (aux));
    }

    // TODO: Implement method addWindow
    std::shared_ptr<PointerDetectorAdvFilter> finalObj;
    finalObj = std::dynamic_pointer_cast<PointerDetectorAdvFilter> (obj);
    if (!finalObj) {
      JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "Object not found or has incorrect type");
      throw e;
    }

    finalObj->addWindow (window);
    return;
  }

  if (methodName == "clearWindows" && params.size() == 0) {
    Json::Value aux;

    // TODO: Implement method clearWindows
    std::shared_ptr<PointerDetectorAdvFilter> finalObj;
    finalObj = std::dynamic_pointer_cast<PointerDetectorAdvFilter> (obj);
    if (!finalObj) {
      JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "Object not found or has incorrect type");
      throw e;
    }

    finalObj->clearWindows ();
    return;
  }

  if (methodName == "trackColorFromCalibrationRegion" && params.size() == 0) {
    Json::Value aux;

    // TODO: Implement method trackColorFromCalibrationRegion
    std::shared_ptr<PointerDetectorAdvFilter> finalObj;
    finalObj = std::dynamic_pointer_cast<PointerDetectorAdvFilter> (obj);
    if (!finalObj) {
      JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "Object not found or has incorrect type");
      throw e;
    }

    finalObj->trackColorFromCalibrationRegion ();
    return;
  }

  if (methodName == "removeWindow" && params.size() == 1) {
    Json::Value aux;
    std::string windowId;

    if (!params.isMember ("windowId")) {
      /* param 'windowId' not present, raise exception */
      JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'windowId' parameter is requiered");
      throw e;
    } else {
      aux = params["windowId"];

      if (!aux.isString ()) {
        /* param 'windowId' has invalid type value, raise exception */
        JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "'windowId' parameter should be a string");
        throw e;
      }

      windowId = aux.asString ();
    }

    // TODO: Implement method removeWindow
    std::shared_ptr<PointerDetectorAdvFilter> finalObj;
    finalObj = std::dynamic_pointer_cast<PointerDetectorAdvFilter> (obj);
    if (!finalObj) {
      JsonRpc::CallException e (JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                                "Object not found or has incorrect type");
      throw e;
    }

    finalObj->removeWindow (windowId);
    return;
  }

  Filter::Invoker::invoke(obj, methodName, params, response);
}

std::string
PointerDetectorAdvFilter::connect(const std::string &eventType, std::shared_ptr<EventHandler> handler)
{
  if ("WindowIn" == eventType) {
    sigc::connection conn = signalWindowIn.connect ([&, handler] (WindowIn event) {
      JsonSerializer s (true);

      s.Serialize ("data", event);
      s.Serialize ("object", this);
      s.JsonValue["type"] = "WindowIn";
      s.JsonValue["subscription"] = handler->getId();
      handler->sendEvent(s.JsonValue);
    });
    handler->setConnection (conn);
    return handler->getId();
  }
  if ("WindowOut" == eventType) {
    sigc::connection conn = signalWindowOut.connect ([&, handler] (WindowOut event) {
      JsonSerializer s (true);

      s.Serialize ("data", event);
      s.Serialize ("object", this);
      s.JsonValue["type"] = "WindowOut";
      s.JsonValue["subscription"] = handler->getId();
      handler->sendEvent(s.JsonValue);
    });
    handler->setConnection (conn);
    return handler->getId();
  }
  return Filter::connect (eventType, handler);
}

} /* kurento */

void
Serialize(std::shared_ptr<kurento::PointerDetectorAdvFilter> &object, JsonSerializer &serializer)
{
  if (!serializer.IsWriter) {
    try {
      std::shared_ptr<kurento::MediaObject> aux;
      aux = kurento::PointerDetectorAdvFilter::Factory::getObject (serializer.JsonValue.asString ());
      object = std::dynamic_pointer_cast<kurento::PointerDetectorAdvFilter> (aux);
      return;
    } catch (kurento::JsonRpc::CallException &ex) {
      kurento::JsonRpc::CallException e (kurento::JsonRpc::ErrorCode::SERVER_ERROR_INIT,
                              "'PointerDetectorAdvFilter' object not found: "+ ex.getMessage());
      throw e;
    }
  }
  std::shared_ptr<kurento::Filter> aux = std::dynamic_pointer_cast<kurento::Filter> (object);

  void Serialize(std::shared_ptr<kurento::Filter> &object, JsonSerializer &serializer);
  Serialize(aux, serializer);
}

void
Serialize(kurento::PointerDetectorAdvFilter &object, JsonSerializer &serializer)
{
  void Serialize(kurento::Filter &object, JsonSerializer &serializer);
  try {
    Serialize(dynamic_cast<kurento::Filter &> (object), serializer);
  } catch (std::bad_cast) {
  }
}
