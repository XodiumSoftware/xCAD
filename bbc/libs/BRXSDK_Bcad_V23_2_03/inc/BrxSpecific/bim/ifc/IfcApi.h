/*
 * Copyright (c) 2019 Bricsys NV
 * All rights reserved.
 */

#pragma once

#include "Export.h"
#include "IfcSchemaId.h"

#include <cstddef>
#include <vector>
#include <iterator>

namespace Ice
{
namespace IfcApi
{;

#define DECLARE_IMPL1()\
class Impl;\
private:\
Impl* m_pImpl;

#define DECLARE_IMPL2(CLASS)\
class Impl;\
private:\
Impl* m_pImpl;\
CLASS(Impl*);

class Entity;
class Variant;
class Model;
class SelectValue;
class VectorValue;

/**
 * Base64-encoded GUID in IFC/STEP.
 * @see <a href="http://www.buildingsmart-tech.org/ifc/IFC2x3/TC1/html/ifcutilityresource/lexical/ifcgloballyuniqueid.htm">IfcGloballyUniqueId</a>.
 * @see <a href="http://en.wikipedia.org/wiki/GUID">Globally unique identifier</a>.
 * @author <a href="mailto:johan.kerckaert@bricsys.com">Johan Kerckaert</a>
 */
class IFCAPI_EXPORT Guid
{
public:
    Guid();
    Guid(const Guid& c);
    Guid(Guid&& c);
    Guid& operator=(const Guid& o);
    Guid& operator=(Guid&& o);
    ~Guid();

    /**
     * Create new GUID.
     */
    static Guid create();

    /**
     * Create from base64-encoded notation.
     * @param base64 buffer of size 23 or more.
     */
    static Guid createFromBase64(const char* base64);

    /**
     * Create from text notation.
     * @param text buffer of size 39 or more.
     */
    static Guid createFromText(const char* text);

    const char* getBase64() const;
    const char* getText() const;

    bool operator==(const Guid& o) const;
    bool operator!=(const Guid& o) const;

    DECLARE_IMPL2(Guid)
};

/**
 * Unicode String encoded in IFC/STEP according to ISO-10303-21.
 * We support the <code>\\S\\</code>, <code>\\X\\</code> and
 * <code>\\X2\\...\\X0\\"</code> encodings, but not the
 * <code>\\P\\</code> and <code>\\X4\\...\\X0\\"</code> encodings.
 * @author <a href="mailto:johan.kerckaert@bricsys.com">Johan Kerckaert</a>
 */
class IFCAPI_EXPORT String
{
public:
    String(const wchar_t* unicode = nullptr);
    String(const String& other);
    String(String&& other);
    String& operator=(const String& other);
    String& operator=(String&& other);
    ~String();

    operator const wchar_t* () const;
    const char* getEncoded() const;
    const wchar_t* c_str() const;
    bool isEmpty() const;
    void setEmpty();

    /// Decode ASCII-encoded string to Unicode string.
    static String decode(const char* encoded);

    DECLARE_IMPL2(String)
};

/**
 * Binary data encoded in IFC/STEP according to ISO-10303-21.
  * @see <a href="https://en.wikipedia.org/wiki/ISO_10303-21#DATA_section"> Binary values</a>.
 * Binary values (bit sequences) are encoded as hexadecimal and surrounded by double quotes,
 * with a leading character indicating the number of unused bits (0, 1, 2, or 3) followed by
 * uppercase hexadecimal encoding of data. The entire binary value is encoded as a single hexadecimal number,
 * with the highest order bits in the first hex character and the lowest order bits in the last one.
 * @author <a href="mailto:natalia.shakhalova@bricsys.com">Natalia Shakhalova</a>
 */
class IFCAPI_EXPORT Binary
{
public:
    Binary(const char* encodedStr = nullptr);
    Binary(const Binary& other);
    Binary(Binary&& other);
    Binary& operator=(const Binary& other);
    Binary& operator=(Binary&& other);
    ~Binary();

    const char* getEncodedString() const;
    void reset(const char* encodedStr);
    size_t numBits() const;
    bool getBit(size_t i) const;
    bool isEmpty() const;
    void resize(size_t nBits);
    /**
     * set all bits to 0
     */
    void clear();

    DECLARE_IMPL2(Binary)
};

/**
 * EXPRESS Logical type with possible values <code>TRUE</code>,
 * <code>FALSE</code> and <code>UNKNOWN</code>.
 * @see <a href="http://en.wikipedia.org/wiki/EXPRESS_%28data_modeling_language%29#Datatypes">EXPRESS data types</a>.
 * @author <a href="mailto:johan.kerckaert@bricsys.com">Johan Kerckaert</a>
 */
class IFCAPI_EXPORT Logical
{
public:
    Logical();
    Logical(bool);
    Logical(const Logical&);
    Logical(Logical&&);
    Logical& operator=(const Logical&);
    Logical& operator=(Logical&&);
    ~Logical();

    bool isKnown() const;
    bool isUnknown() const;
    operator bool() const;

    DECLARE_IMPL2(Logical)
};

enum class Result
{
    eOk,
    eNotInitialized,
    eWrongName,
    eWrongType,
    eInternalError
};

/**
 * Descriptor of IFC container classes.
 * Supported classes are listed in API/AggregationsList.h
*/
class IFCAPI_EXPORT VectorDesc
{
public:
    VectorDesc();
    VectorDesc(const VectorDesc&) = delete;
    VectorDesc& operator=(const VectorDesc&) = delete;
    ~VectorDesc();

    DECLARE_IMPL1()
    friend VectorValue;
};

/**
 * Represnts container value attribute
 */
class IFCAPI_EXPORT VectorValue
{
public:
    /**
     * Creates VectorValue according to the descriptor.
     * e.g. VectorValue vv(Set_1_IfcCurve, Ice::EIfcSchemaId::eIFC2X3);
     */
    VectorValue(const VectorDesc&, Ice::EIfcSchemaId);
    VectorValue(const VectorValue&);
    VectorValue(VectorValue&&);
    VectorValue& operator=(const VectorValue&);
    VectorValue& operator=(VectorValue&&);
    ~VectorValue();

    Variant operator[](unsigned int index) const;
    /**
     * Appends objects to the end of container.
     * Underlying type of Variant should be consistent with container's descriptor,
     * otherwise Result::eWrongType is returned.
     * e.g. 
     * VectorValue vv(Array_1_2_double, Ice::EIfcSchemaId::eIFC2X3);
     * assert(vv.add(Variant(4.0)) == Result::eOk);
     * assert(vv.add(Variant(true)) == Result::eWrongType)
     */
    Result add(const Variant& value);
    unsigned int size() const;
    bool remove(unsigned int index);
    void clear();

    /**
     * Return true if VectorDesc is not presented in given schema.
     * e.g.
     * SelectValue vv1(List_3_3_IfcPositiveInteger, Ice::EIfcSchemaId::eIFC2X3);
     * assert(vv1.isNull());
     * SelectValue vv2(List_3_3_IfcPositiveInteger, Ice::EIfcSchemaId::eIFC4);
     * assert(!vv2.isNull());
     */
    bool isNull() const;

    class IFCAPI_EXPORT const_iterator : public std::iterator<std::random_access_iterator_tag, Variant>
    {
        const VectorValue* m_pVector = nullptr;
        std::size_t m_idx = 0;

    public:
        const_iterator()=default;
        const_iterator(const VectorValue* vv, std::size_t i);

        const_iterator& operator++();
        const_iterator& operator--();
        bool operator==(const const_iterator& rhs) const;
        bool operator!=(const const_iterator& rhs) const;
        Variant operator*() const;

        const_iterator operator++(int);
        const_iterator operator--(int);

        bool operator<(const const_iterator& rhs) const;
        bool operator<=(const const_iterator& rhs) const;
        bool operator>(const const_iterator& rhs) const;
        bool operator>=(const const_iterator& rhs) const;

        const_iterator operator+(std::ptrdiff_t rhs) const;
        const_iterator& operator+=(std::ptrdiff_t rhs);
        const_iterator operator-(std::ptrdiff_t rhs) const;
        const_iterator& operator-=(std::ptrdiff_t rhs);

        std::ptrdiff_t operator-(const const_iterator& rhs);

        Variant operator[](std::size_t k) const;

        static void swap(const_iterator& a, const_iterator& b);

    };

    const_iterator begin() const;
    const_iterator end() const;

    DECLARE_IMPL2(VectorValue)
};

/**
 * Descriptor of IFC selector classes.
 * Supported classes are listed in API/SelectorsList.h
*/
class IFCAPI_EXPORT SelectorDesc
{
public:
    SelectorDesc();
    SelectorDesc(const SelectorDesc&) = delete;
    SelectorDesc& operator=(const SelectorDesc&) = delete;
    ~SelectorDesc();

    operator const char* () const;

    DECLARE_IMPL1()
    friend SelectValue;
};

/**
 * Represents selector attribute
 */
class IFCAPI_EXPORT SelectValue
{
public:
    /**
     * Creates SelectValue according to the descriptor.
     * e.g. SelectValue sv(IfcSizeSelect, Ice::EIfcSchemaId::eIFC2X3);
     */
    SelectValue(const SelectorDesc&, Ice::EIfcSchemaId);
    SelectValue(const SelectValue&);
    SelectValue& operator=(const SelectValue&);
    SelectValue& operator=(SelectValue&&);
    SelectValue(SelectValue&&);
    ~SelectValue();

    /**
     * Returns selected value.
     */
    Variant getValue() const;

    /**
     * Returns selected IFC type.
     * e.g.
     * SelectValue sv(IfcSizeSelect, Ice::EIfcSchemaId::eIFC2X3);
     * if (strcmp(sv.tag(), IfcRatioMeasure) == 0) {...}
     * else if (strcmp(sv.tag(), IfcLengthMeasure) == 0) {...}
     * ...
     */
    const char* tag() const;

    /**
     * Set underlying value.
     * e.g.
     * SelectValue sv(IfcSizeSelect, Ice::EIfcSchemaId::eIFC2X3);
     * sv.setValue(IfcRatioMeasure, Variant(0.5));
     * auto value = sv.getValue();
     * assert(value.type() == ValueType::eReal && value.getReal() == 0.5);
     * assert(strcmp(sv.tag(), IfcRatioMeasure) == 0);
     */
    Result setValue(const char* tag, const Variant&);

    /**
     * Return true if SelectorDesc is not presented in given schema.
     * e.g.
     * SelectValue sv1(IfcBendingParameterSelect, Ice::EIfcSchemaId::eIFC2X3);
     * assert(sv1.isNull());
     * SelectValue sv2(IfcBendingParameterSelect, Ice::EIfcSchemaId::eIFC4);
     * assert(!sv2.isNull());
     */
    bool isNull() const;

    DECLARE_IMPL2(SelectValue)
};

/**
 * Represents enum value attribute.
 * Supported enum values are listed in API/EnumValueList.h
 */
class IFCAPI_EXPORT EnumValue
{
public:
    EnumValue(const char* stringValue = nullptr);
    EnumValue(const EnumValue&);
    EnumValue(EnumValue&&);
    EnumValue& operator=(const EnumValue&);
    EnumValue& operator=(EnumValue&&);
    ~EnumValue();

    const char* getValue() const;

    /**
     * Set enum value
     * e.g.
     * EnumValue ev(eAREAUNIT);
     * ev.setValue(eABSORBEDDOSEUNIT);
     */
    void setValue(const char* stringValue);

    DECLARE_IMPL2(EnumValue)
};

/**
 * Supported value types of Variant
 */
enum class ValueType
{
    eBool,
    eInt,
    eUInt,
    eReal,
    eString,
    eEntity,
    eLogical,
    eBinary,
    eGuid,
    eEnum,
    eSelect,
    eVector,
    eEmpty
};

/**
 * Variant represents union of types.
 * Variant holds a value of one of its types.
 * Variant supports all possible attribute values of IFC entities.
 */
class IFCAPI_EXPORT Variant
{
public:
    Variant();
    Variant(const Variant&);
    Variant(Variant&&);
    Variant& operator=(const Variant&);
    Variant& operator=(Variant&&);
    ~Variant();

    Variant(int);
    Variant(bool);
    Variant(unsigned);
    Variant(double);
    Variant(const String&);
    Variant(const Logical&);
    Variant(const Binary&);
    Variant(const Guid&);
    Variant(Guid&&);
    Variant(const VectorValue&);
    Variant(VectorValue&&);
    Variant(const SelectValue&);
    Variant(SelectValue&&);
    Variant(const EnumValue&);
    Variant(EnumValue&&);
    Variant(const Entity&);

    Variant& operator=(int);
    Variant& operator=(bool);
    Variant& operator=(unsigned);
    Variant& operator=(double);
    Variant& operator=(const String&);
    Variant& operator=(const Logical&);
    Variant& operator=(const Binary&);
    Variant& operator=(const Guid&);
    Variant& operator=(Guid&&);
    Variant& operator=(const VectorValue&);
    Variant& operator=(VectorValue&&);
    Variant& operator=(const SelectValue&);
    Variant& operator=(SelectValue&&);
    Variant& operator=(const EnumValue&);
    Variant& operator=(EnumValue&&);
    Variant& operator=(const Entity&);

    /* returns underlying int value
    */
    int getInt() const;

    /* returns underlying bool value
    */
    bool getBool() const;

    /* returns underlying unsigned value
    */
    unsigned getUInt() const;

    /* returns underlying double value
    */
    double getReal() const;

    /* returns a copy of underlying String data
    */
    String getString() const;

    /* returns underlying Entity value
    */
    Entity getEntity() const;

    /* returns a copy of underlying Logical data
    */
    Logical getLogical() const;

    /* returns a copy of underlying Binary data
    */
    Binary getBinary() const;

    /* returns a copy of underlying Guid data
    */
    Guid getGuid() const;

    /* returns a copy of underlying VectorValue data
    */
    VectorValue getVector() const;

    /* returns a copy of underlying SelectValue data
    */
    SelectValue getSelect() const;

    /* returns a copy of underlying EnumValue data
    */
    EnumValue getEnum() const;

    /* returns type of underlying data
    */
    ValueType type() const;

    DECLARE_IMPL2(Variant)
};

/**
 * Descriptor of IFC entity classes.
 * Supported classes are listed in API/EntitiesList.h
 */
class IFCAPI_EXPORT EntityDesc
{
public:
    EntityDesc();
    EntityDesc(const EntityDesc&) = delete;
    EntityDesc& operator=(const EntityDesc&) = delete;
    ~EntityDesc();
    operator const char* () const;
    bool operator==(const EntityDesc&) const;

    /**
     * return true if 'this' instance of IFC class is derived from 'obj' IFC class
     */
    bool isDerivedFrom(const EntityDesc& obj, Ice::EIfcSchemaId eSchema) const;

    DECLARE_IMPL1()
    friend Entity;
};

/**
 * Class which represents the reference to underlying IFC entity.
 */
class IFCAPI_EXPORT Entity
{
public:
    Entity();

    /*
     * Copy and move constructor and assignment operator.
     * Note, no new entries of IFC entity are created in corresponding IFC model.
     */
    Entity(const Entity&);
    Entity(Entity&&);
    Entity& operator=(const Entity&);
    Entity& operator=(Entity&&);
    ~Entity();
    /**
     * Id of the entity in an IFC file
     */
    int ifcId() const;

    /**
     * Returns attribute with specified name.
     * List of all attribute names is listed in API/AttributesList.h
     * If entity doesn't have attribute with specified name, Result::eWrongName is returned
     * If attribute is optional and not initialized, Result::eNotInitialized is returned
     * e.g.
     * Variant height;
     * assert(windowEnt.getAttribute(OverallHeight, height) == Result::eOk);
     */
    Result getAttribute(const char* attbName, Variant& attribValue) const;
    
    /**
     * Set value of attribute with specified name.
     * List of all attribute names is listed in API/AttributesList.h
     * If entity doesn't have attribute with specified name, Result::eWrongName is returned
     * If type of @attribValue is not consistent with attribute type, Result::eWrongType is returned
     * e.g.
     * Variant height(1000.0);
     * assert(windowEnt.setAttribute(OverallHeight, height) == Result::eOk);
     */
    Result setAttribute(const char* attribName, const Variant& attribValue);
    
    /**
     * Get class descriptor
     */
    const EntityDesc* isA() const;
    
    /**
     * Find if the class is derived from a given descriptor
     */
    bool isKindOf(const EntityDesc&) const;
    bool isNull() const;

    /**
     * Array of elements referring this entity.
     */
    std::vector<Entity> getInverseRefs() const;

    /**
     * Creates entity with specified type within IFC model.
     * If EntityDesc is not defined within the model schema, Entity::s_null is returned.
     * e.g.
     * auto wall = Entity::create(model, IfcWall);
     */
    static Entity create(Model& model, const EntityDesc& entityDesc);

    static const Entity s_null;

    DECLARE_IMPL2(Entity)
};

/**
 * Represents header of IFC file
 */
class IFCAPI_EXPORT Header
{
public:
    Header();
    Header(const Header&);
    Header(Header&&);
    Header& operator=(const Header&);
    Header& operator=(Header&&);
    ~Header();

    String fileDescription() const;
    String implementationLevel() const;
    void setFileDescription(const String& str);

    String fileName() const;
    String timeStamp() const;
    String author() const;
    String organization() const;
    String preprocessorVersion() const;
    String originatingSystem() const;
    String authorization() const;

    void setFileName(const String& str);
    void setTimeStamp(const String& str);
    void setAuthor(const String& str);
    void setOrganization(const String& str);
    void setPreprocessorVersion(const String& str);
    void setOriginatingSystem(const String& str);
    void setAuthorization(const String& str);

    String fileSchema() const;
    void setFileSchema(const String& str);

private:
    DECLARE_IMPL1()
    friend Model;
};

class IFCAPI_EXPORT Model
{
public:
    /**
    * Destroy object
    */
    void release();

    /**
     * Get number of entities contained in Model.
     */
    size_t getNumEntities() const;

    /**
     * Get an entity from Model.
     */
    Entity get(size_t index) const;
    
    /**
     * Get schema descriptor
     */
    Ice::EIfcSchemaId schemaId() const;

    /**
     * Write this model to the given stream.
     */
    bool write(const wchar_t* fileName, const Header& header);

    /**
     * Create new Ifc model.
     * Note: caller is the owner of the instance and should release it.
     * Calling release() will destroy it.
     */
    static Model* create(Ice::EIfcSchemaId schemaId);

    /**
     * Read an Model from the given stream.
     * Note: caller is the owner of the instance and should release it.
     * Calling release() will destroy it.
     */
    static Model* read(const wchar_t* fileName, Header* header = nullptr);

    DECLARE_IMPL2(Model)
private:
    ~Model();
};

#undef DECLARE_IMPL1
#undef DECLARE_IMPL2
} // namespace IfcApi
} // namespace Ice
