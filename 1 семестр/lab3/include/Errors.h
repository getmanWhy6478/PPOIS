#include <exception>
#include <string>

class GalleryError : public std::exception {
protected:
    std::string message;
public:
    explicit GalleryError(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InvalidTicketNumberError : public GalleryError {
public:
    InvalidTicketNumberError() : GalleryError("Invalid ticket number.") {}
};

class TicketAlreadyUsedError : public GalleryError {
public:
    TicketAlreadyUsedError() : GalleryError("Ticket has already been used.") {}
};

class TicketExpiredError : public GalleryError {
public:
    TicketExpiredError() : GalleryError("Ticket has expired.") {}
};

class VisitorNotFoundError : public GalleryError {
public:
    VisitorNotFoundError() : GalleryError("Visitor not found.") {}
};

class ArtworkNotFoundError : public GalleryError {
public:
    ArtworkNotFoundError() : GalleryError("Artwork not found.") {}
};

class DuplicateArtworkError : public GalleryError {
public:
    DuplicateArtworkError() : GalleryError("Duplicate artwork detected.") {}
};

class InvalidArtworkLocationError : public GalleryError {
public:
    InvalidArtworkLocationError() : GalleryError("Invalid artwork location.") {}
};

class ConservationRequiredError : public GalleryError {
public:
    ConservationRequiredError() : GalleryError("Artwork requires conservation before exhibition.") {}
};

class ExhibitionNotFoundError : public GalleryError {
public:
    ExhibitionNotFoundError() : GalleryError("Exhibition not found.") {}
};

class ExhibitionCapacityExceededError : public GalleryError {
public:
    ExhibitionCapacityExceededError() : GalleryError("Exhibition capacity exceeded.") {}
};

class PaymentFailedError : public GalleryError {
public:
    PaymentFailedError() : GalleryError("Payment failed.") {}
};

class TransportationError : public GalleryError {
public:
    TransportationError() : GalleryError("Transportation error occurred.") {}
};
