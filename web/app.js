const offices = {
    Karachi: [
        "NADRA Saddar",
        "NADRA Clifton",
        "NADRA North Nazimabad",
        "Passport Office Clifton",
        "Passport Office Saddar"
    ],
    Lahore: [
        "NADRA Gulberg",
        "NADRA Model Town",
        "NADRA Johar Town",
        "Passport Office Gulberg",
        "Passport Office Mall Road"
    ],
    Islamabad: [
        "NADRA G-6",
        "NADRA F-8",
        "NADRA I-9",
        "Passport Office F-6",
        "Passport Office G-9"
    ]
};

let appointmentCounter = 100;

function updateOffices() {
    const citySelect = document.getElementById('city');
    const officeSelect = document.getElementById('office');
    
    if (citySelect && officeSelect) {
        citySelect.addEventListener('change', function() {
            officeSelect.innerHTML = '<option value="">Select Office</option>';
            
            const selectedCity = this.value;
            if (selectedCity && offices[selectedCity]) {
                offices[selectedCity].forEach(office => {
                    const option = document.createElement('option');
                    option.value = office;
                    option.textContent = office;
                    officeSelect.appendChild(option);
                });
            }
        });
    }
}

function generateConfirmationCode(city) {
    const cityCode = {
        'Karachi': 'KHI',
        'Lahore': 'LHR',
        'Islamabad': 'ISB'
    };
    
    appointmentCounter++;
    return `APT-${cityCode[city]}-${appointmentCounter}`;
}

function handleBooking(event) {
    event.preventDefault();
    
    const formData = {
        name: document.getElementById('name').value,
        cnic: document.getElementById('cnic').value,
        phone: document.getElementById('phone').value,
        city: document.getElementById('city').value,
        office: document.getElementById('office').value,
        service: document.getElementById('service').value,
        date: document.getElementById('date').value,
        time: document.getElementById('time').value
    };
    
    const confirmationCode = generateConfirmationCode(formData.city);
    
    const appointment = {
        ...formData,
        confirmationCode: confirmationCode
    };
    
    let appointments = JSON.parse(localStorage.getItem('appointments') || '[]');
    appointments.push(appointment);
    localStorage.setItem('appointments', JSON.stringify(appointments));
    
    document.getElementById('bookingForm').style.display = 'none';
    document.getElementById('confirmation').classList.remove('hidden');
    document.getElementById('confirmCode').textContent = confirmationCode;
}

function initBookingPage() {
    const bookingForm = document.getElementById('bookingForm');
    if (bookingForm) {
        updateOffices();
        bookingForm.addEventListener('submit', handleBooking);
    }
}

if (document.getElementById('bookingForm')) {
    initBookingPage();
}
